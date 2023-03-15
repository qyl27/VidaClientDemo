#include "qgt/WindowFactory.h"
#include "qgt/FontRenderer.h"

using namespace glm;
using namespace std;

int main() {
    auto w = WindowFactory().title("TestWindow").size(1024, 768).scaleMode(SCALE).posMode(PIXEL_NEG)
            .defaultContext().forceAspectRatio(16, 9).scalable(true).sizeLimitMin(200, 200)
            .sizeLimitMax(2000, 2000).windowedFullscreen().construct();

    auto font = FontRenderer().loadFont("resources/LXGWWenKaiLite-Regular.ttf", 3, 1);    // the 2nd arg mode: 1 for ascii, 2 for cjk, 3 for all.

    wstring str = L"Hello, world!";

    while (!w.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0F, 1.0F, 1.0F, 1.0F);

        w.postToScreen();
        glfwPollEvents();

        FontRenderer().render(font, str, 10, 10, 1, vec3(0, 0, 0));
    }
    return 0;
}
