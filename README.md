# ImAnim
Demo that uses easing functions for animation with ImGui

![Example Window](https://github.com/cipperly/ImAnim/blob/main/doc/demo.gif)

This includes a Visual Studio 2019 solution and project; no cmake yet.  Copy the classes from this project into yours to use with your application.

The classes for the animation are setup similar to the animation framework in Qt.  Example of coloring text:

```cpp
static ImVec4 vTextColor(1.0F, 1.0F, 1.0F, 1.0F);
static imanim::ImVec4Anim *pColorAnim = nullptr;

ImGui::TextColored(vTextColor, "Colored Text");
if (pColorAnim == nullptr)
{
    // Create the animation and attach it to the ImVec4 used to color the text
    pColorAnim = new imanim::ImVec4Anim(&vTextColor);
    // Animate from white text to red text
    pColorAnim->setStartValue(ImVec4(1, 1, 1, 1));
    pColorAnim->setEndValue(ImVec4(1, 0, 0, 1));
    // Set the animation duration for a single loop (in seconds)
    pColorAnim->setDuration(1.0);
    // Set the number of loops of animation; -1 loops forever
    pColorAnim->setLoopCount(-1);
    pColorAnim->setEasingCurve(imanim::EasingCurve::Type::Linear);
    pColorAnim->start();
}
else
{
    // Update the animation
    pColorAnim->update();
}
```

Note that if you want to fade out an object, then you would just go from an alpha of 1 to 0; to fade in, go from an alpha of 0 to 1.

Example of animating the position of an ImGui window:

```cpp
static ImVec2 vWinPos(20, 100);
static imanim::ImVec2Anim *pWinPosAnim = nullptr;

if (pWinPosAnim == nullptr)
{
    // Create the animation and attach it to the ImVec2 used to position the window
    pWinPosAnim = new imanim::ImVec2Anim(&vWinPos);
    // Setup 3 key frames; move from left to right then back to start
    pWinPosAnim->setStartValue(ImVec2(20, 100));
    pWinPosAnim->setKeyValueAt(0.5, ImVec2(400, 100));
    pWinPosAnim->setEndValue(ImVec2(20, 100));
    // Set the duration for a single loop to 2.5 seconds
    pWinPosAnim->setDuration(2.5);
    // Set the loop count to -1, which loops forever
    pWinPosAnim->setLoopCount(-1);
    pWinPosAnim->setEasingCurve(imanim::EasingCurve::Type::InOutQuad);
    pWinPosAnim->start();
}
else
{
    // Update the animation
    pWinPosAnim->update();
}

// Draw the window
ImGui::SetNextWindowPos(vWinPos);
ImGui::Begin("Test Window");
ImGui::Text("Some text");
ImGui::End();
```

Note that
```cpp
pWinPosAnim->setStartValue(ImVec2(20, 100));
```
is the same as this:
```cpp
pWinPosAnim->setKeyValueAt(0.0, ImVec2(20, 100));
```

and
```cpp
pWinPosAnim->setEndValue(ImVec2(20, 100));
```
is the same as
```cpp
pWinPosAnim->setKeyValueAt(1.0, ImVec2(20, 100));
```

You can create a group of animations that run in a sequence like so:

```cpp
// Create a group of animations to run in a sequence
auto *pColorAnimGroup =
    new imanim::SequentialAnimationGroup();

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

pColorAnimGroup->start();
```

See testSequential.cpp for a complete example.
