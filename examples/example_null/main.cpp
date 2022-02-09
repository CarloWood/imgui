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

    for (int n = 0; n < 3; n++)
    {
        io.DisplaySize = ImVec2(150, 50);
        io.DeltaTime = 1.0f / 60.0f;

        switch (n)
        {
          case 0:
            break;
          case 1:
            io.AddMousePosEvent(75, 25);
            io.AddMouseButtonEvent(0, true);
            break;
          case 2:
//            io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
            io.AddMousePosEvent(76, 24);
            io.AddMouseButtonEvent(0, false);
//            io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
            break;
        }

        printf("NewFrame() %d\n", n);
        ImGui::NewFrame();

        if (ImGui::Button("Trigger Event", ImVec2(134, 134)))
          printf("Button clicked!\n");
        else
          printf("Button not clicked!\n");

        ImGui::EndFrame();
        ImGui::Render();
    }

    printf("DestroyContext()\n");
    ImGui::DestroyContext();
}
