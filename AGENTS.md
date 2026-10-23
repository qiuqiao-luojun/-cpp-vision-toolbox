# AGENTS.md

## 构建与运行

- 依赖：CMake >= 3.16、VS 2022 x64、OpenCV（`core` + `imgproc`）。
- 当前 OpenCV 不可用：`build/CMakeCache.txt` 中 `OpenCV_DIR=OpenCV_DIR-NOTFOUND`，`D:\opencv` 为空目录，`build/` 是配置失败后的残留（没有生成 `.sln`）。
- 安装 OpenCV 后重新配置，用 `-DOpenCV_DIR` 指向其 `build` 目录（含 `OpenCVConfig.cmake`）：

  ```powershell
  cmake -S . -B build -DOpenCV_DIR="<opencv>/build"
  ```

  若仍失败，删除 `build/` 后重试；不要手改 `build/CMakeCache.txt`。

- 构建与运行（VS 多配置生成器，产物在 `build\<Config>\`）：

  ```powershell
  cmake --build build --config Release
  .\build\Release\vision.exe
  ```

- 单目标构建：`cmake --build build --config Debug --target vision`
- 无测试 / lint / 格式化配置；验证即构建并运行 `vision.exe`，应打印 OpenCV 版本与 `blur ok, size = [200 x 200]`。

## 结构

- 单文件程序：`main.cpp` → 可执行目标 `vision`（目标名不是项目名 `cpp-vision-toolbox`）。
- `find_package` 只启用 `core` 和 `imgproc`；新增 `highgui`、`imgcodecs` 等模块的调用时，必须同步加入 `COMPONENTS`，否则链接失败。
- 强制 C++17（`CMAKE_CXX_STANDARD 17` + `CMAKE_CXX_STANDARD_REQUIRED ON`）。
- 源码含 UTF-8 中文注释；在 Windows 控制台输出乱码是代码页问题，不代表文件损坏。

## 注意

- 目录中没有 `.git`（只有 `.gitignore`），不要假设 git 命令可用。
- `build/` 已被忽略，属于机器特定生成物，不要提交或手改。
