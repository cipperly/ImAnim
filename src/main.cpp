// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImVec2Anim.h"
#include "ImVec4Anim.h"
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

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
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

        {
            static ImVec4 vTextColor(1.0F, 1.0F, 1.0F, 1.0F);
            static ImVec4 vStartColor(1.0F, 1.0F, 1.0F, 1.0F);
            static ImVec4 vEndColor(1.0F, 0.0F, 0.0F, 1.0F);
            static float fColorDurationInSecs = 2.0F;
            static int nColorLoopCount = 1;
            static int nColorEasingFuncIndex = 0;
            static imanim::ImVec4Anim *pColorAnim = nullptr;

            static ImVec2 vWinPos((ImGui::GetMainViewport()->WorkPos.x + 20),
                (ImGui::GetMainViewport()->WorkPos.y + 400));
            static ImVec2 vWinSize(200, 50);
            static imanim::ImVec2Anim *pWinPosAnim = nullptr;
            static imanim::ImVec2Anim *pWinSizeAnim = nullptr;

            ImGui::Begin("Demo Animation", nullptr,
                ImGuiWindowFlags_NoTitleBar |
                ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize);

            // Display some colored text
            ImGui::TextColored(vTextColor, "Colored Text");
            ImGui::ColorEdit4("Start Color", (float *)&vStartColor);
            ImGui::ColorEdit4("End Color", (float *)&vEndColor);
            if (ImGui::SliderFloat("Duration", &fColorDurationInSecs, 0.1F,
                5.0F, "%.2f secs") && (pColorAnim != nullptr))
            {
                pColorAnim->setDuration(fColorDurationInSecs);
            }
            if (ImGui::SliderInt("Loop Count", &nColorLoopCount, -1, 10) &&
                (pColorAnim != nullptr))
            {
                pColorAnim->setLoopCount(nColorLoopCount);
            }
            ImGui::SameLine();
            helpMarker("Number of loops for animation. 0 = no animation; "
                "-1 = loop forever");
            ImGui::Combo("Easing Function", &nColorEasingFuncIndex,
                imanim::EasingCurve::TYPE_STRINGS,
                IM_ARRAYSIZE(imanim::EasingCurve::TYPE_STRINGS));
            if (ImGui::Button("Start Color Animation"))
            {
                if (pColorAnim == nullptr)
                {
                    // Create the animation and attach it to the ImVec4 being
                    // used to color the text (vTextColor)
                    pColorAnim = new imanim::ImVec4Anim(&vTextColor);
                }
                pColorAnim->setStartValue(vStartColor);
                pColorAnim->setEndValue(vEndColor);
                // The duration below is in seconds and is the duration for a
                // single loop
                pColorAnim->setDuration(fColorDurationInSecs);
                // The loop count below defaults to 1 if not set; set to -1 to
                // loop forever
                pColorAnim->setLoopCount(nColorLoopCount);
                // See https://easings.net/ for a list of the easing functions
                pColorAnim->setEasingCurve(static_cast<
                    imanim::EasingCurve::Type>(nColorEasingFuncIndex));
                pColorAnim->start();
            }
            ImGui::SameLine();
            if (ImGui::Button("Stop Color Animation") &&
                (pColorAnim != nullptr))
            {
                // Stop the animate...there is no way to pause it yet
                pColorAnim->stop();
            }
            if (pColorAnim != nullptr)
            {
                // The update must be called while the animation is running
                pColorAnim->update();
            }
            ImGui::NewLine();

            if (ImGui::Button("Start WinPos Animation"))
            {
                if (pWinPosAnim == nullptr)
                {
                    // Create the animation and attach it to the ImVec2 being
                    // used for the window position (vWinPos).  Note that this
                    // is just animating the ImVec2 object, so you can use a
                    // similar approach for animating other ImGui ImVec2
                    // attributes.
                    pWinPosAnim = new imanim::ImVec2Anim(&vWinPos);
                    const ImGuiViewport *pViewport = ImGui::GetMainViewport();
                    pWinPosAnim->setStartValue(ImVec2(
                        (pViewport->WorkPos.x + 20),
                        (pViewport->WorkPos.y + 400)));
                    pWinPosAnim->setKeyValueAt(0.5, ImVec2(
                        (pViewport->WorkSize.x - 300),
                        (pViewport->WorkPos.y + 400)));
                    pWinPosAnim->setEndValue(ImVec2(
                        (pViewport->WorkPos.x + 20),
                        (pViewport->WorkPos.y + 400)));
                    pWinPosAnim->setEasingCurve(
                        imanim::EasingCurve::Type::InOutQuad);
                    pWinPosAnim->setDuration(2.5);
                    pWinPosAnim->setLoopCount(-1);
                }
                pWinPosAnim->start();
            }
            ImGui::SameLine();
            if (ImGui::Button("Stop WinPos Animation"))
            {
                if (pWinPosAnim != nullptr)
                {
                    pWinPosAnim->stop();
                    vWinPos = pWinPosAnim->getStartValue();
                }
            }
            if (pWinPosAnim != nullptr)
            {
                pWinPosAnim->update();
            }
            ImGui::NewLine();

            if (ImGui::Button("Start WinSize Animation"))
            {
                if (pWinSizeAnim == nullptr)
                {
                    pWinSizeAnim = new imanim::ImVec2Anim(&vWinSize);
                    pWinSizeAnim->setStartValue(ImVec2(200, 50));
                    pWinSizeAnim->setKeyValueAt(0.5, ImVec2(600, 300));
                    pWinSizeAnim->setEndValue(ImVec2(200, 50));
                    pWinSizeAnim->setEasingCurve(
                        imanim::EasingCurve::Type::InOutQuart);
                    pWinSizeAnim->setDuration(2.0);
                    pWinSizeAnim->setLoopCount(-1);
                }
                pWinSizeAnim->start();
            }
            ImGui::SameLine();
            if (ImGui::Button("Stop WinSize Animation"))
            {
                if (pWinSizeAnim != nullptr)
                {
                    pWinSizeAnim->stop();
                    vWinSize = pWinSizeAnim->getStartValue();
                }
            }
            if (pWinSizeAnim != nullptr)
            {
                pWinSizeAnim->update();
            }

            ImGui::NewLine();
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();

            ImGui::SetNextWindowPos(vWinPos);
            ImGui::SetNextWindowSize(ImVec2(300, 200));
            ImGui::Begin("Test WinPos Animation", nullptr,
                ImGuiWindowFlags_NoDecoration);
            ImGui::Text("Position Animation");
            ImGui::End();

            ImGui::SetNextWindowPos(ImVec2(500, 30));
            ImGui::SetNextWindowSize(vWinSize);
            ImGui::Begin("Test WinSize Animation", nullptr,
                ImGuiWindowFlags_NoDecoration);
            ImGui::Text("Size Animation");
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
