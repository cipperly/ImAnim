// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImVec2Anim.h"
#include "ImVec4Anim.h"
#include "SequentialAnimationGroup.h"
#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void helpMarker(const char *desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char *glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_demo_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // Begin animation testing
        {
            static imanim::SequentialAnimationGroup *pColorAnimGroup = nullptr;
            static ImVec4 vText1Color(1, 1, 1, 1);
            static ImVec4 vText2Color(1, 0, 0, 1);
            static ImVec4 vText3Color(0, 1, 0, 1);

            ImGui::Begin("Demo Animation", nullptr,
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize);

            // Display some colored text
            ImGui::TextColored(vText1Color, "Text1");
            ImGui::SameLine();
            ImGui::TextColored(vText2Color, "Text2");
            ImGui::SameLine();
            ImGui::TextColored(vText3Color, "Test3");
            bool bIsColorAnimRunning = (pColorAnimGroup != nullptr) &&
                (pColorAnimGroup->getState() ==
                imanim::AbstractAnimation::State::Running);
            ImGui::BeginDisabled(bIsColorAnimRunning);
            if (ImGui::Button("Start Color Animation"))
            {
                if (pColorAnimGroup == nullptr)
                {
                    // Create a group of animations to run in a sequence
                    pColorAnimGroup = new imanim::SequentialAnimationGroup();
                    imanim::ImVec4Anim *pColorAnim1 = new imanim::ImVec4Anim(
                        &vText1Color);
                    pColorAnim1->setStartValue(ImVec4(1, 1, 1, 1));
                    pColorAnim1->setEndValue(ImVec4(1, 0, 0, 1));
                    pColorAnim1->setDuration(1.5);
                    pColorAnim1->setEasingCurve(
                        imanim::EasingCurve::Type::Linear);
                    imanim::ImVec4Anim *pColorAnim2 = new imanim::ImVec4Anim(
                        &vText2Color);
                    pColorAnim2->setStartValue(ImVec4(1, 0, 0, 1));
                    pColorAnim2->setEndValue(ImVec4(0, 1, 0, 1));
                    pColorAnim2->setDuration(1.5);
                    pColorAnim2->setEasingCurve(
                        imanim::EasingCurve::Type::Linear);
                    imanim::ImVec4Anim *pColorAnim3 = new imanim::ImVec4Anim(
                        &vText3Color);
                    pColorAnim3->setStartValue(ImVec4(0, 1, 0, 1));
                    pColorAnim3->setEndValue(ImVec4(0, 0, 1, 1));
                    pColorAnim3->setDuration(1.5);
                    pColorAnim3->setEasingCurve(
                        imanim::EasingCurve::Type::Linear);
                    // Add the 3 animations to the sequential group
                    pColorAnimGroup->addAnimation(pColorAnim1);
                    pColorAnimGroup->addAnimation(pColorAnim2);
                    pColorAnimGroup->addAnimation(pColorAnim3);
                }
                else if (pColorAnimGroup->getState() !=
                    imanim::AbstractAnimation::State::Running)
                {
                    // Reset color on the texts before starting
                    vText2Color = ImVec4(1, 0, 0, 1);
                    vText3Color = ImVec4(0, 1, 0, 1);
                }
                pColorAnimGroup->start();
            }
            ImGui::EndDisabled();
            ImGui::SameLine();
            ImGui::BeginDisabled(!bIsColorAnimRunning);
            if (ImGui::Button("Stop Color Animation") &&
                (pColorAnimGroup != nullptr))
            {
                // Stop the animate
                pColorAnimGroup->stop();
                vText1Color = ImVec4(1, 1, 1, 1);
                vText2Color = ImVec4(1, 0, 0, 1);
                vText3Color = ImVec4(0, 1, 0, 1);
            }
            ImGui::EndDisabled();
            if (pColorAnimGroup != nullptr)
            {
                // The update must be called while the animation is running
                pColorAnimGroup->update();
            }
            ImGui::NewLine();

            static ImVec2 vStartWin1Pos(
                (ImGui::GetMainViewport()->WorkPos.x + 20),
                (ImGui::GetMainViewport()->WorkPos.y + 300));
            static ImVec2 vWin1Pos = vStartWin1Pos;
            static ImVec2 vWin2Pos(vStartWin1Pos.x + 400, vStartWin1Pos.y);
            static imanim::SequentialAnimationGroup *pWinPosAnimGroup = nullptr;

            bool bIsPosAnimRunning = (pWinPosAnimGroup != nullptr) &&
                (pWinPosAnimGroup->getState() ==
                    imanim::AbstractAnimation::State::Running);
            ImGui::BeginDisabled(bIsPosAnimRunning);
            if (ImGui::Button("Start WinPos Animation"))
            {
                if (pWinPosAnimGroup == nullptr)
                {
                    // Create the animation sequence
                    pWinPosAnimGroup = new imanim::SequentialAnimationGroup();
                    imanim::ImVec2Anim *pWin1PosAnim = new imanim::ImVec2Anim(
                        &vWin1Pos);
                    pWin1PosAnim->setStartValue(vStartWin1Pos);
                    pWin1PosAnim->setEndValue(ImVec2((vStartWin1Pos.x + 300),
                        vStartWin1Pos.y));
                    pWin1PosAnim->setEasingCurve(
                        imanim::EasingCurve::Type::InOutQuad);
                    pWin1PosAnim->setDuration(1.5);
                    imanim::ImVec2Anim *pWin2PosAnim = new imanim::ImVec2Anim(
                        &vWin2Pos);
                    pWin2PosAnim->setStartValue(ImVec2(vStartWin1Pos.x + 400,
                        vStartWin1Pos.y));
                    pWin2PosAnim->setEndValue(ImVec2((vStartWin1Pos.x + 700),
                        vStartWin1Pos.y));
                    pWin2PosAnim->setEasingCurve(
                        imanim::EasingCurve::Type::InOutQuad);
                    pWin2PosAnim->setDuration(1.5);
                    pWinPosAnimGroup->addAnimation(pWin1PosAnim);
                    pWinPosAnimGroup->addAnimation(pWin2PosAnim);
                }
                else if (pWinPosAnimGroup->getState() !=
                    imanim::AbstractAnimation::State::Running)
                {
                    // Reset the position of the second window
                    vWin2Pos = ImVec2(vStartWin1Pos.x + 400, vStartWin1Pos.y);
                }
                pWinPosAnimGroup->start();
            }
            ImGui::EndDisabled();
            ImGui::SameLine();
            ImGui::BeginDisabled(!bIsPosAnimRunning);
            if (ImGui::Button("Stop WinPos Animation"))
            {
                if (pWinPosAnimGroup != nullptr)
                {
                    pWinPosAnimGroup->stop();
                    vWin1Pos = vStartWin1Pos;
                    vWin2Pos = ImVec2(vStartWin1Pos.x + 400, vStartWin1Pos.y);
                }
            }
            ImGui::EndDisabled();
            if (pWinPosAnimGroup != nullptr)
            {
                pWinPosAnimGroup->update();
            }

            ImGui::NewLine();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();

            ImGui::SetNextWindowPos(vWin1Pos);
            ImGui::SetNextWindowSize(ImVec2(100, 100));
            ImGui::Begin("Window1", nullptr, ImGuiWindowFlags_NoDecoration);
            ImGui::Text("Win1");
            ImGui::End();

            ImGui::SetNextWindowPos(vWin2Pos);
            ImGui::SetNextWindowSize(ImVec2(100, 100));
            ImGui::Begin("Window2", nullptr, ImGuiWindowFlags_NoDecoration);
            ImGui::Text("Win2");
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y *
            clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
