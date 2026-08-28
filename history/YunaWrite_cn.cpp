#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#define MAX 200
const std::string VER = "0.1";
static void clear_OS()
{
#if defined (_WIN32)
    system("cls");
#else
    system("clear");
#endif
}
struct filebody {
    std::string p_name;
    std::string p_content;
};
struct buildinto {
    struct filebody filenumber[MAX];
    int p_size;
};

void add(buildinto* ptr)
{
    if (ptr->p_size == MAX)
    {
        std::cerr << "文件数量已达上限，无法继续添加" << std::endl;
        return;
    }
    else {
        std::cout << "文件名：";
        std::string name;
        std::getline(std::cin, name);
        ptr->filenumber[ptr->p_size].p_name = name;
        std::cout << "文件内容（输入 OVER 结束）：" << std::endl;
        std::string content;
        std::string true_Content;
        while (1)
        {
            std::getline(std::cin, content);
            if (content == "OVER")
            {
                ptr->filenumber[ptr->p_size].p_content = true_Content;
                break;
            }
            true_Content += content + "\n";
        }
        ptr->p_size++;
    }


}
void showfile(buildinto* ptr) {
    if (ptr->p_size == 0)
    {
        std::cout << "当前没有虚拟文件" << std::endl;
    }
    else {
        for (int j = 0;j < ptr->p_size;j++)
        {
            std::cout << "=======================虚拟文件系统=======================" << std::endl;
            std::cout << "[" << j << "]" << std::endl;
            std::cout << "文件名：" << ptr->filenumber[j].p_name << std::endl;
            std::cout << "文件内容：" << std::endl;
            std::cout << "===================================================" << std::endl;
            std::cout << ptr->filenumber[j].p_content << std::endl;
            std::cout << "===================================================" << std::endl;
            std::cout << "" << std::endl;
        }
    }
}
static void Patch()
{
    std::cout << "==YunaIDE PATCH START==" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.1 About the file space issue" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.2 About create a new file - cls" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.3 About create a new file(std::cin name? content ....)" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.4 About Run html,cpp" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.5 About HELP,back,Patch,cerr about else at code layer,copyright notice" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.6 About content loop issue,enter make else issue" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.7 About opexe safety,virfl layer,patch in code layer,cpp safety,infor" << std::endl;
    std::cout << "==YunaWrite PATCH START==" << std::endl;
    std::cout << "YunaWrite Patch: 0.1 About Github Change,YunaWrite,0.1.ver" << std::endl;
    std::cout << "==ALL PATCH END==" << std::endl;
}
static void helpList()
{
    std::cout << "==帮助菜单==" << std::endl;
    std::cout << "提示：本工具在 ASCII 输入下表现最佳。如需输入中文或表情符号，请使用 Windows 终端或在 Visual Studio 调试器外部运行。" << std::endl;
    std::cout << "help        查看帮助菜单（任意层级可用）" << std::endl;
    std::cout << "cls         清屏（任意层级可用）" << std::endl;
    std::cout << "==代码层==" << std::endl;
    std::cout << "adder       在程序目录下创建文件夹（代码层）" << std::endl;
    std::cout << "addfl       在程序目录下创建文件（代码层）" << std::endl;
    std::cout << "patch       查看程序补丁历史（代码层）" << std::endl;
    std::cout << "quit        退出整个程序（代码层）" << std::endl;
    std::cout << "support     查看系统支持的文件后缀（代码层）" << std::endl;
    std::cout << "infor       查看 YunaWrite 信息（代码层）" << std::endl;
    std::cout << "OVER        结束文件内容写入（输入内容时）" << std::endl;
    std::cout << "==运行层==" << std::endl;
    std::cout << "run         进入运行层" << std::endl;
    std::cout << "cpp         运行 C++ 演示（仅打开终端）" << std::endl;
    std::cout << "opexe       直接用默认程序打开文件（运行层）" << std::endl;
    std::cout << "back        返回上一层（运行层 / 虚拟文件系统层）" << std::endl;
    std::cout << "==虚拟文件系统层==" << std::endl;
    std::cout << "virfl       进入虚拟文件系统层" << std::endl;
    std::cout << "addfl       创建虚拟文件（虚拟文件系统层）" << std::endl;
    std::cout << "del         删除虚拟文件（虚拟文件系统层）" << std::endl;
    std::cout << "list        列出所有虚拟文件及其内容（虚拟文件系统层）" << std::endl;
    std::cout << "delall      删除所有虚拟文件（虚拟文件系统层）" << std::endl;
    std::cout << "chna        修改虚拟文件名（虚拟文件系统层）" << std::endl;
    std::cout << "chcon       修改虚拟文件内容（虚拟文件系统层）" << std::endl;
    std::cout << "back        返回上一层（运行层 / 虚拟文件系统层）" << std::endl;
    std::cout << "find        查找虚拟文件并显示内容（虚拟文件系统层）" << std::endl;
    std::cout << "==帮助结束==" << std::endl;
}
static void information_os()
{
    std::cout << "==信息==" << std::endl;
    std::cout << "名称：YunaWrite" << std::endl;
    std::cout << "作者：Biriks-off" << std::endl;
    std::cout << "环境：C++20, VS 2026, Microsoft Windows 10" << std::endl;
    std::cout << "版本：" << VER << std::endl;
    std::cout << "语言:简体中文" << std::endl;
    std::cout << "创建日期（0.0.1）：2026.8.14" << std::endl;
    std::cout << "==信息结束==" << std::endl;

}
static void support_os()
{
    std::cout << R"(YunaWrite 支持的文件后缀：
Windows
.exe .com .bat
.cmd .msi .scr
.cpl .reg .vbs
.vbe .js .jse
.wsf .wsh .msc
.htm .html .txt
.log .rtf .doc
.docx .xls .xlsx
.xlsm .csv .ppt
.pptx .pptm .pps
.ppsx .mp3 .wav
.wma .aac .flac
.m4a .ogg .mp4
.avi .mov .wmv
.flv .mkv .webm
.mpeg .mpg .jpg
.jpeg .png .gif
.bmp .psd

macOS
.app .dmg .pkg
.command .terminal .scpt
.applescript .workflow .sh
.bash .zsh .csh
.py .pl .rb
.run .bin .appimage
(以及所有常见的媒体/文档类型，
由系统关联程序打开)

Linux
.desktop .sh .bash
.zsh .csh .py
.pl .rb .run
.bin .appimage
(以及无后缀但具有执行权限的二进制文件；
媒体/文档同样由系统关联程序打开))";
}
int orinit(buildinto* ptr, std::string name) {
    for (int fg = 0;fg < ptr->p_size;fg++) {
        if (ptr->filenumber[fg].p_name == name) {
            return fg;
        }
    }
    return -1;

}
void changefiles(buildinto* ptr) {
    std::cout << "旧文件名：";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "新文件名：";
        std::string namenew;

        std::getline(std::cin, namenew);
        ptr->filenumber[ret].p_name = namenew;
        std::cout << "修改成功" << std::endl;
    }
    else
    {
        std::cout << "未找到该文件" << std::endl;
    }
}
void changecontent(buildinto* ptr) {
    std::cout << "文件名：";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "旧内容：" << std::endl;
        std::cout << ptr->filenumber[ret].p_content << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cout << "新内容（输入 OVER 结束）：";
        std::string namecon;
        std::string true_namecon;
        while (1) {
            std::getline(std::cin, namecon);
            if (namecon == "OVER")
            {
                ptr->filenumber[ret].p_content = true_namecon;
                break;
            }
            true_namecon += namecon + "\n";
        }
        std::cout << "修改成功" << std::endl;
    }
    else
    {
        std::cout << "未找到该文件" << std::endl;
    }
}

void delfile(buildinto* ptr) {
    std::cout << "要删除的文件名：";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1) {
        for (int fd = ret;fd < ptr->p_size - 1;fd++)
        {
            ptr->filenumber[fd] = ptr->filenumber[fd + 1];
        }
        ptr->p_size--;
        std::cout << "\"" << name << "\" 删除成功" << std::endl;
    }
    else
    {
        std::cout << "未找到该文件" << std::endl;
    }
}
void searchf(buildinto* ptr) {
    std::string name;
    std::cout << "文件名：";
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "文件名：" << ptr->filenumber[ret].p_name << std::endl;
        std::cout << "内容：" << std::endl;
        std::cout << ptr->filenumber[ret].p_content << std::endl;
        std::cout << "===============================================" << std::endl;
    }
    else
    {
        std::cout << "未找到该文件" << std::endl;
    }
}
void delallfiles(buildinto* ptr)
{
    std::cout << "确定要删除所有虚拟文件吗？" << std::endl;
    std::cout << "1. 确定删除" << std::endl;
    std::cout << "2. 取消" << std::endl;
    while (1)
    {
        std::string chooses;
        std::getline(std::cin, chooses);
        if (chooses == "1")
        {
            ptr->p_size = 0;
            std::cout << "已全部删除" << std::endl;
            break;
        }
        if (chooses == "2")
        {
            break;
        }
        else {
            std::cout << "无效输入，请选择 1 或 2" << std::endl;
        }
    }
}
int main()
{
    buildinto ptr;
    ptr.p_size = 0;
    std::cout << "YUNA YunaWrite " << "[版本: " << VER << " ]" << std::endl;
    std::cout << "输入 \"help\" 查看帮助菜单" << std::endl;
    std::cout << "语言:简体中文" << std::endl;
    std::cout << std::endl;
    static std::string name2, name3, name1, cppcode;
    while (1)
    {
        std::cout << "(@YUNA)" << "C:>";
        std::string code;
        std::getline(std::cin, code);
        if (code.empty()) continue;
        if (code == "adder")
        {
            std::cout << "文件夹名称：";
            std::string name1;
            std::getline(std::cin, name1);
            std::filesystem::create_directories("./" + name1);
        }
        else if (code == "help")
        {
            helpList();
        }
        else if (code == "cls")
        {
            clear_OS();
        }
        else if (code == "quit")
        {
            break;
        }
        else if (code == "support")
        {
            support_os();
        }
        else if (code == "virfl")
        {
            while (true)
            {
                std::cout << "(@YUNA)Vircode>>>";
                std::string codevir;
                std::getline(std::cin, codevir);
                if (codevir.empty()) continue;
                if (codevir == "back")
                {
                    std::cout << "返回主界面" << std::endl;
                    break;
                }
                else if (codevir == "addfl")
                {
                    add(&ptr);
                }
                else if (codevir == "list")
                {
                    showfile(&ptr);
                }
                else if (codevir == "del")
                {
                    delfile(&ptr);
                }
                else if (codevir == "delall")
                {
                    delallfiles(&ptr);
                }
                else if (codevir == "find")
                {
                    searchf(&ptr);
                }
                else if (codevir == "chcon")
                {
                    changecontent(&ptr);
                }
                else if (codevir == "chna")
                {
                    changefiles(&ptr);
                }
                else if (codevir == "help")
                {
                    helpList();
                }
                else if (codevir == "cls")
                {
                    clear_OS();
                }
                else {
                    std::cerr << "YunaWrite 无法处理" << "\"" << codevir << "\"" << std::endl;
                }

            }
        }
        else if (code == "patch")
        {
            Patch();
        }
        else if (code == "infor")
        {
            information_os();
        }
        else if (code == "addfl")
        {
            std::cout << "文件名：";
            std::string name2;
            std::getline(std::cin, name2);
            std::cout << "文件扩展名（不需要输入点号）" << std::endl;
            std::string name3;
            std::getline(std::cin, name3);
            std::cout << "文件内容（输入 OVER 结束）：" << std::endl;
            std::string content;
            std::string true_Content;
            while (std::getline(std::cin, content))
            {
                if (content == "OVER")
                {
                    break;
                }
                true_Content += content + "\n";
            }
            std::filesystem::path theFile = std::filesystem::current_path();
            std::filesystem::path theBuild = theFile / (name2 + "." + name3);
            std::filesystem::create_directories(theBuild.parent_path());
            std::ofstream file(theBuild);
            if (file.is_open()) {
                file << true_Content;
                file.close();
                std::cout << "文件已保存" << std::endl;
            }
            else {
                std::cerr << "文件保存失败" << std::endl;
            }

        }
        else if (code == "run")
        {

            while (1) {
                std::cout << "(@YUNA)Run>>>";
                std::string runcode;
                std::getline(std::cin, runcode);
                if (runcode.empty()) continue;
                if (runcode == "cpp") {
#if defined (_WIN32)
                    system("start cmd");
#elif defined (__APPLE__)
                    system("open -a Terminal .");
#elif defined (__linux__)
                    system("x-terminal-emulator &");
#endif
                }
                else if (runcode == "back")
                {
                    std::cout << "返回主界面" << std::endl;
                    break;
                }
                else if (runcode == "opexe") {
                    std::cout << "文件名：";
                    std::string name_Html;
                    std::getline(std::cin, name_Html);
                    std::string cmd;
#if defined(_WIN32)
                    cmd = "start \"\" \"" + name_Html + "\"";
#elif defined(__APPLE__)
                    cmd = "open \"" + name_Html + "\"";
#else
                    cmd = "xdg-open \"" + name_Html + "\"";
#endif
                    system(cmd.c_str());
                }
                else if (runcode == "help")
                {
                    helpList();
                }
                else if (runcode == "cls")
                {
                    clear_OS();
                }
                else {
                    std::cerr << "YunaWrite 无法处理" << "\"" << runcode << "\"" << std::endl;
                }
            }
        }
        else {
            std::cerr << "YunaWrite 无法处理" << "\"" << code << "\"" << std::endl;
        }
    }
}
