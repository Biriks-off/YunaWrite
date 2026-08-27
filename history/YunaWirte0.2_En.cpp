#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#define MAX 200
const std::string VER = "0.2";
static void mailLookAbout()
{
    std::cout << "==YunaWrite"<<VER<< "==" << std::endl;
    std::cout << "1.Contributors:" << std::endl;
    std::cout << "Biriks-off" << std::endl;
    std::cout << "2.NEWS:" << std::endl;
    std::cout << "-virfl supports android" << std::endl;
    std::cout << "-add list,chcon,del,mv,find in the CODE layer" << std::endl;
    std::cout << "-make CODE plus RUN" << std::endl;
    std::cout << "-add mail(just this) and Contributors" << std::endl;
    std::cout << "==YunaWriteMail END==" << std::endl;
}


static void Patch()
{
    std::cout << "YunaIDE Patch: 0.0.1 About the file space issue" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.2 About create a new file - cls" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.3 About create a new file(std::cin name? content ....)" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.4 About CODE html,cpp" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.5 About HELP,back,Patch,cerr about else at code layer,copyright notice" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.6 About content loop issue,enter make else issue" << std::endl;
    std::cout << "YunaIDE Patch: 0.0.7 About opexe safety,virfl layer,patch in code layer,cpp safety,infor" << std::endl;
    std::cout << "YunaWrite Patch: 0.1 About Github Change,YunaWrite,0.1.ver" << std::endl;
    std::cout << "YunaWrite Patch: 0.2 About CODE del;Code move,chcon,find,list,mail;android;CODE plus Mail,CODE" << std::endl;
    std::cout << "==ALL PATCH END==" << std::endl;
}
class filebody {
public:
    std::string p_name;
    std::string p_content;
};

class buildinto {
public:
    filebody filenumber[MAX];
    int p_size;
};

void add(buildinto* ptr)
{
    if (ptr->p_size == MAX)
    {
        std::cerr << "FULLFILES!cannot add" << std::endl;
        return;
    }
    else {
        std::cout << "Name:";
        std::string name;
        std::getline(std::cin, name);
        ptr->filenumber[ptr->p_size].p_name = name;
        std::cout << "Content:" << std::endl;
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
        std::cout << "No files" << std::endl;
    }
    else {
        for (int j = 0;j < ptr->p_size;j++)
        {
            std::cout << "=======================VIRFL=======================" << std::endl;
            std::cout << "[" << j << "]" << std::endl;
            std::cout << "Name:" << ptr->filenumber[j].p_name << std::endl;
            std::cout << "Contect:" << std::endl;
            std::cout << "===================================================" << std::endl;
            std::cout << ptr->filenumber[j].p_content << std::endl;
            std::cout << "===================================================" << std::endl;
            std::cout << "" << std::endl;
        }
    }
}
static void helpList()
{
    std::cout << "==HELP START==" << std::endl;
    std::cout << "Note: This shell works best with ASCII input. For Chinese characters or emoji, please use Windows Terminal or CODE outside Visual Studio debugger." << std::endl;
    std::cout << "help        View the help memu(any level)" << std::endl;
    std::cout << "cls         Clear screen(any level)" << std::endl;
    std::cout << "==CODE==" << std::endl;
    std::cout << "adder       Build a folder in the program folder" << std::endl;
    std::cout << "addfl       Build a file in the program folder" << std::endl;
    std::cout << "patch       View the program's patch history" << std::endl;
    std::cout << "quit        Exit the entire program,implemented" << std::endl;
    std::cout << "mv          Move a file/folder" << std::endl;
    std::cout << "del         Delete a file/folder" << std::endl;
    std::cout << "chna        Change a file's name" << std::endl;
    std::cout << "chcon       Change a file's content" << std::endl;
    std::cout << "find        Search for a file" << std::endl;
    std::cout << "support     View the supported file extensions(opexe)" << std::endl;
    std::cout << "infor       View the information of YunaWrite" << std::endl;
    std::cout << "OVER        Finish writing the file contet(When u writing content)" << std::endl;
    std::cout << "CODE        Enter to the CODE layer" << std::endl;
    std::cout << "cpp         CODE the cpp(Only open Terminal)" << std::endl;
    std::cout << "opexe       CODE the file directly" << std::endl;
    std::cout << "mail        View the information of mail" << std::endl;
    std::cout << "==virfl==" << std::endl;
    std::cout << "virfl       Enter the virtual file system" << std::endl;
    std::cout << "addfl       Build a file" << std::endl;
    std::cout << "del         Delete a file" << std::endl;
    std::cout << "list        List the contents and information of all current files" << std::endl;
    std::cout << "delall      Delete all current files" << std::endl;
    std::cout << "chna        Change a file's name" << std::endl;
    std::cout << "chcon       Change a file's content" << std::endl;
    std::cout << "back        Renturn to the code layer" << std::endl;
    std::cout << "find        Search for a file and list its content" << std::endl;
    std::cout << "==HELP END==" << std::endl;
}
static void information_os()
{
    std::cout << "==INFORMATION START==" << std::endl;
    std::cout << "Name:YunaWrite" << std::endl;
    std::cout << "Creator:Biriks-off" << std::endl;
    std::cout << "Environment:C++20,VS 2026,Microsoft Windows 10" << std::endl;
    std::cout << "Version:" << VER << std::endl;
    std::cout << "Language:English" << std::endl;
    std::cout << "Create Date(0.0.1): 2026.8.14" << std::endl;
    std::cout << "==INFORMATION END==" << std::endl;

}
static void support_os()
{
    std::cout << R"(YunaWirte Support Suffix:
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
    .CODE .bin .appimage
    (plus all common media/docs
    above, which open via
    associated apps)

    Linux
    .desktop .sh .bash
    .zsh .csh .py
    .pl .rb .CODE
    .bin .appimage
    (plus no-extension binaries
    with execute permission;
    media/docs open as well))";
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
    std::cout << "Old Name:";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "New Name:";
        std::string namenew;

        std::getline(std::cin, namenew);
        ptr->filenumber[ret].p_name = namenew;
        std::cout << "Change succeeded" << std::endl;
    }
    else
    {
        std::cout << "No find" << std::endl;
    }
}
void changecontent(buildinto* ptr) {
    std::cout << "Name:";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "Old Content:" << std::endl;
        std::cout << ptr->filenumber[ret].p_content << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cout << "New Content:";
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
        std::cout << "Change succeeded" << std::endl;
    }
    else
    {
        std::cout << "No find" << std::endl;
    }
}

void delfile(buildinto* ptr) {
    std::cout << "Delete(file's name):";
    std::string name;
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1) {
        for (int fd = ret;fd < ptr->p_size - 1;fd++)
        {
            ptr->filenumber[fd] = ptr->filenumber[fd + 1];
        }
        ptr->p_size--;
        std::cout << "\"" << name << ".word" << "\"   " << "delete succeeded:)" << std::endl;
    }
    else
    {
        std::cout << "Sorry,we didn't find this file" << std::endl;
    }
}
void searchf(buildinto* ptr) {
    std::string name;
    std::cout << "File's name:";
    std::getline(std::cin, name);
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "Name:" << ptr->filenumber[ret].p_name << std::endl;
        std::cout << "Content:" << std::endl;
        std::cout << ptr->filenumber[ret].p_content << std::endl;
        std::cout << "===============================================" << std::endl;
    }
    else
    {
        std::cout << "No find" << std::endl;
    }
}
void delallfiles(buildinto* ptr)
{
    std::cout << "Are u sure you want to delete all files in Yours?" << std::endl;
    std::cout << "1.Agree" << std::endl;
    std::cout << "2.No" << std::endl;
    while (1)
    {
        std::string chooses;
        std::getline(std::cin, chooses);
        if (chooses == "1")
        {
            ptr->p_size = 0;
            std::cout << "Delete succeeded" << std::endl;
            break;
        }
        if (chooses == "2")
        {
            break;
        }
        else {
            std::cout << "No find" << std::endl;
        }
    }
}
static void clear_OS()
{
#if defined (_WIN32)
    system("cls");
#else
    system("clear");
#endif
}
int main()
{
    buildinto ptr;
    ptr.p_size = 0;
    std::cout << "YUNA YunaWrite " << "[Version: " << VER << " ]" << std::endl;
    std::cout << "Enter \"help\" to view the help memu" << std::endl;
    std::cout << "Language:English" << std::endl;
    std::cout << std::endl;
    static std::string name2, name3, name1, cppcode;
    while (1)
    {
        std::cout << "(@YUNA)CODE>>>";
        std::string code;
        std::getline(std::cin, code);
        code.erase(0, code.find_first_not_of(" \t"));
        code.erase(code.find_last_not_of(" \t") + 1);
        if (code.empty()) continue;
        if (code == "adder")
        {
            std::cout << "FOLDER NAME:";
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
        else if (code == "del")
        {
            std::cout << "Delete Name:";
            std::string name_rm;
        std::getline(std::cin, name_rm);
            if (std::filesystem::exists(name_rm))
            {
                std::filesystem::remove(name_rm);
                std::cout << "Delete " << "\"" << name_rm << "\"" << "succeeded" << std::endl;
            }
            else
            {
                std::cerr << "YunaWrite can't find " << name_rm << std::endl;
            }
        }
        else if (code == "mv")
        {
            std::cout << "If u need move a file to a folder " << std::endl;
            std::cout << "FILE NAME:b" << std::endl;
            std::cout << "FOLDER NAME:a" << std::endl;
            std::cout << "You need enter:" << std::endl;
            std::cout << "Original File / Folder Name:b" << std::endl;
            std::cout << "Object File / Folder Name:a/b" << std::endl;
            std::cout << std::endl;
            std::string name_og_move;
            std::string name_af_move;
            std::cout << "Original File / Folder Name:";
            std::getline(std::cin, name_og_move);
            std::cout << "Object File / Folder Name:";
            std::getline(std::cin, name_af_move);
            if (std::filesystem::exists(name_og_move))
            {
                try
                {
                    std::filesystem::rename(name_og_move, name_af_move);
                    std::cout << name_og_move << "->" << name_af_move << " succeeded" << std::endl;
                }
                catch (std::filesystem::filesystem_error& a)
                {
                    std::cout << "YunaWriteError:" << a.what() << std::endl;
                }

            }
            else
            {
                std::cout << "YunaWrite can't find" << "\"" << name_og_move << "\"" << std::endl;
            }

        }
        else if (code == "find")
        {
            std::string filename;
            std::cout << "File Name:" << std::endl;
            std::getline(std::cin, filename);
            if (std::filesystem::exists(filename))
            {
                try
                {
                    std::cout << "YunaWrite found" << "\"" << filename << "\"" << "succeeded" << std::endl;
                }
                catch (std::filesystem::filesystem_error& a)
                {
                    std::cout << "YunaWriteError:" << a.what() << std::endl;
                }

            }
            else
            {
                std::cout << "YunaWrite can't find" << "\"" << filename << "\"" << std::endl;
            }
           
          }
        
        else if (code == "mail")
        {
            mailLookAbout();
        }
        else if (code == "support")
        {
            support_os();
        }
        else if (code == "hello" || code == "hi" || code == "hey")
        {
            std::cout << "Hello,welcome to YunaWrite" << std::endl;
        }
        else if (code == "virfl")
        {
            while (true)
            {
                std::cout << "(@YUNA)Vircode>>>";
                std::string codevir;
                std::getline(std::cin, codevir);
                codevir.erase(0, codevir.find_first_not_of(" \t"));
                codevir.erase(codevir.find_last_not_of(" \t") + 1);
                if (codevir.empty()) continue;
                if (codevir == "back")
                {
                    std::cout << "Back CODE" << std::endl;
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
                    std::cerr << "YunaWrite can't process" << "\"" << codevir << "\"" << std::endl;
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
            std::cout << "FILE NAME:";
            std::string name2;
            std::getline(std::cin, name2);
            std::cout << "FILE EXTENSION:" << std::endl;
            std::cerr << "TIP:You don't have to write \".\" " << std::endl;
            std::string name3;
            std::getline(std::cin, name3);
            std::cout << "FILE CONTENT:" << std::endl;
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
            }

        }
        else if (code == "chcon")
        {
            std::string name_chcon;
            std::string name_chcon_content;
            std::string name_chcon_true;
            std::getline(std::cin, name_chcon);
            if (std::filesystem::exists(name_chcon))
            {
                try
                {
                    std::cout << "New Content:" << std::endl;
                    while (std::getline(std::cin, name_chcon_content))
                    {
                        if (name_chcon_content == "OVER")
                        {
                            break;
                        }
                        name_chcon_true += name_chcon_content + "\n";
                    }
                    std::ofstream filech(name_chcon);
                    filech << name_chcon_true;
                    filech.close();
                    std::cout << "Change the content about " << "\"" << name_chcon << "\"" << "succeeded" << std::endl;
                }
                catch (std::filesystem::filesystem_error& o)
                {
                    std::cerr << "YunaWriteError:" << o.what() << std::endl;
                }
            }
            else
            {
                std::cerr << "YunaWrite can't find" << "\"" << name_chcon << "\"" << std::endl;
            }
        }
        else if (code == "list")
        {
            try {
                for (const auto& entry : std::filesystem::directory_iterator("."))
                {
                    std::cout << entry.path().filename().string() << std::endl;
                }
            }
            catch (std::filesystem::filesystem_error& listfile)
            {
                std::cout << "YunaWriteError:" << listfile.what() << std::endl;
            }
        }
        else if (code == "cpp") {
#if defined (_WIN32)
            system("start cmd");
#elif defined (__APPLE__)
            system("open -a Terminal .");
#elif defined (__linux__)
            system("x-terminal-emulator &");
#endif
        }

        else if (code == "opexe") {
            std::cout << "FILE Name:";
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
        else {
            std::cerr << "YunaWrite can't process" << "\"" << code << "\"" << std::endl;
        }
    }
}
