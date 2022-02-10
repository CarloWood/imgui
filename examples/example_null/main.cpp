#include "imgui.h"
#include <cstdio>

int main()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Build atlas
    unsigned char* tex_pixels = nullptr;
    int tex_w, tex_h;
    io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);

    bool last_frame = false;
    for (int n = 0; n < 20; n++)
    {
        io.DisplaySize = ImVec2(150, 50);
        io.DeltaTime = 1.0f / 60.0f;

        switch (n)
        {
          case 0:
//            io.AddFocusEvent(true);
            break;
          case 1:
            io.AddMousePosEvent(75, 25);
            io.AddMouseButtonEvent(0, true);
            break;
          case 2:
//            break;
//          case 3:
            io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
            io.AddMousePosEvent(76, 24);
            io.AddMouseButtonEvent(0, false);
            io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
            break;
          default:
            last_frame = true;
            break;
        }
        if (last_frame)
          break;

        printf("NewFrame() %d\n", n);
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::Begin("SingleButton", nullptr,
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoSavedSettings);

        if (ImGui::Button("Trigger Event", ImVec2(134, 134)))
          printf(">>>>>>>>>>> Button clicked!\n");
        else
          printf(">>>>>>>>>>> Button not clicked!\n");

        ImGui::End();

        ImGui::EndFrame();
        ImGui::Render();
    }

    printf("DestroyContext()\n");
    ImGui::DestroyContext();
}
