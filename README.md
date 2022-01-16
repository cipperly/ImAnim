# ImAnim
Demo that uses easing functions for animation with ImGui

![Example Window](https://github.com/cipperly/ImAnim/blob/main/doc/demo.gif)

This includes a Visual Studio 2019 solution and project; no cmake yet.

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
