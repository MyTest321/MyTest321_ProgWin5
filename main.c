#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define MY_MIN(a, b) (a) <= (b) ? (a) : (b)
#define MY_MAX(a, b) (a) >= (b) ? (a) : (b)

typedef struct MyStrView {
    char* begin;
    size_t len;
} MyStrView;

void MyStrView_setByBeginEnd(MyStrView* view, char* begin, char* end);
void MyStrView_setByLen(MyStrView* view, char* begin, size_t len);

MyStrView* createMyStrView(char* begin, char* end) {
    MyStrView* ret = (MyStrView*)malloc(sizeof(MyStrView));
    if (ret == NULL) {
        printf("malloc error");
        exit(1);
    }
    MyStrView_setByBeginEnd(ret, begin, end);
    return ret;
}

void MyStrView_setByBeginEnd(MyStrView* view, char* begin, char* end) {
    MyStrView_setByLen(view, begin, end - begin);
}

void MyStrView_setByLen(MyStrView* view, char* begin, size_t len) {
    view->begin = begin;
    view->len = len;
}

void MyStrView_free(MyStrView** view) {
    free(*view);
    *view = NULL;
}

void MyStrView_reset(MyStrView* view) {
    view->begin = NULL;
    view->len = 0;
}

void MyStrView_c_str(MyStrView* view, char* buf, size_t bufSize) {
    memcpy_s(buf, bufSize, view->begin, view->len);
    if (bufSize > view->len) {
        buf[view->len] = '\0';
    }
    buf[bufSize - 1] = '\0';
}

void MyStrView_substr(MyStrView* dst, MyStrView* src, int st, size_t count) {
    if (count <= 0) return;

    if (src->len <= st) {
        return;
    }

    char* p = src->begin + st;
    char* srcEnd = src->begin + src->len;
    char* dstEnd = p + count;

    dst->begin = p;
    size_t dstLen = dstEnd - p;
    dst->len = MY_MIN(count, dstLen);
}

void MyStrView_print(MyStrView* view) {
    char dirNameBuf[MAX_PATH + 1];
    MyStrView_c_str(view, dirNameBuf, sizeof(dirNameBuf));
    printf("%s\n", dirNameBuf);
}

void g_currentExePath(char* buf, size_t bufSize) {
    GetModuleFileName(NULL, buf, bufSize);
}

MyStrView g_dirName(MyStrView path) {
    char* begin = path.begin;
    char* end   = begin + path.len;

    MyStrView ret;
    ret.begin = NULL;
    ret.len   = 0;

    for (char* c = end; c != begin; c--) {
        if (*c == '/' || *c == '\\') {
            ret.begin = begin;
            ret.len   = c - begin;
            break;
        }
    }
    return ret;
}

BOOL g_getCurrentDir(char* buf, size_t bufSize) {
    if (!GetCurrentDirectory(bufSize, buf)) {
        printf("GetCurrentDirectory error");
        return FALSE;
    }
    return TRUE;
}

BOOL g_setCurrentDir(const char* dir) {
    if (!SetCurrentDirectory(dir)) {
        printf("SetCurrentDirectory error");
        return FALSE;
    }
    return TRUE;
}

void g_setWorkingDir() {
    char tmp[MAX_PATH + 1];
    g_currentExePath(tmp, sizeof(tmp));

#if _DEBUG
    printf("%s\n", tmp);
#endif

    static const char* kPrefix = MY_CMAKE_ROOT_DIR"/build/ProgWin5-x86-windows/";
    const size_t kPerfixSize = strlen(kPrefix);

    MyStrView path;
    path.begin = tmp;
    path.len = strlen(tmp);

    MyStrView dirName = g_dirName(path);

#if _DEBUG
    MyStrView_print(&dirName);
#endif

    // F:\books\ProgWin5\build\ProgWin5-windows\Chap03\HelloWin\Debug
    char dirNameBuf[MAX_PATH + 1];
    MyStrView_c_str(&dirName, dirNameBuf, sizeof(dirNameBuf));

    // 1: Chap03\HelloWin\Debug
    // 2: Chap03\HelloWin\Release
    MyStrView relativePath;
    MyStrView_reset(&relativePath);
    MyStrView_substr(&relativePath, &dirName, kPerfixSize, dirName.len - kPerfixSize);
#if _DEBUG
    MyStrView_print(&relativePath);
#endif

    char relativePathBuf[MAX_PATH + 1];
    MyStrView_c_str(&relativePath, relativePathBuf, sizeof(relativePathBuf));

    char newDir[MAX_PATH + 1];
    snprintf(newDir, sizeof(newDir), "%s/../../../../../%s/../", dirNameBuf, relativePathBuf);
#if _DEBUG
    printf("set current dir: %s\n", newDir);
#endif

    g_setCurrentDir(newDir);

#if _DEBUG
    g_getCurrentDir(tmp, sizeof(tmp));
    printf("\ncurrent dir: %s\n", tmp);
#endif

}

// -------------------------------------------------
#if _DEBUG
	#pragma comment( linker, "/subsystem:console" )
int main(int argc, const char** argv) {
    g_setWorkingDir();

	return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOWDEFAULT);
}
#else
	#pragma comment( linker, "/subsystem:windows" )
#endif