#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

const std::string VER = "0.3";

static void sp_help()
{
    std::cout << "opexe:" << std::endl;
    std::cout << "   -opexe+file name     Run the file" << std::endl;
    std::cout << "   -opexe+Enter         Enter the program directory" << std::endl;
    std::cout << "GCC:" << std::endl;
    std::cout << "   -cpp(code)           Build a .bat/.command/.sh file" << std::endl;
    std::cout << "setting.txt:" << std::endl;
    std::cout << "   -white               White words" << std::endl;
    std::cout << "   -blue                Blue  words" << std::endl;
    std::cout << "   -red                 Red   words" << std::endl;
    std::cout << "   -green               Green words" << std::endl;
    std::cout << "mail.txt:" << std::endl;
    std::cout << "   -mail(code)          View the mail" << std::endl;
}

static void show_mail()
{
    std::ifstream file_mail("mail.txt");
    if (!file_mail.is_open())
    {
        std::ofstream outmail("mail.txt");
        outmail << "-Version:" << VER << std::endl;
        outmail << "-Contributors:" << std::endl;
        outmail << "1.Biriks-off" << std::endl;
        outmail << "-NEWS:" << std::endl;
        outmail << "   1.Vector memory management (No more MAX 200)" << std::endl;
        outmail << "   2.Color changing via settings.txt" << std::endl;
        outmail << "   3.Tamed Ctrl+Z/D as an instant 'Back' shortcut" << std::endl;
        outmail << "   4.Added 0/1 binary true/false judgment" << std::endl;
        outmail << "   5.Added mail & setting interfaces" << std::endl;
        outmail.close();
        file_mail.open("mail.txt");
    }
    std::string line_mail;
    while (std::getline(file_mail, line_mail))
    {
        std::cout << line_mail << std::endl;
    }
    file_mail.close();
}

struct yw_setting
{
    std::string color_setting = "white";
};

static void load_setting(yw_setting& fsy)
{
    std::ifstream setting_file("setting.txt");
    if (!setting_file.is_open())
    {
        std::ofstream outset("setting.txt");
        outset << "white" << std::endl;
        outset.close();
        fsy.color_setting = "white";
        return;
    }
    std::string line_setting;
    int line_num = 0;
    while (std::getline(setting_file, line_setting))
    {
        line_setting.erase(0, line_setting.find_first_not_of(" \t"));
        line_setting.erase(line_setting.find_last_not_of(" \t") + 1);
        if (line_setting.empty()) continue;
        if (!line_setting.empty() && line_setting.back() == '\r') line_setting.pop_back();
        if (line_num == 0)
        {
            if (line_setting == "blue") fsy.color_setting = "blue";
            else if (line_setting == "red") fsy.color_setting = "red";
            else if (line_setting == "white") fsy.color_setting = "white";
            else fsy.color_setting = "green";
        }
        line_num++;
    }
    setting_file.close();
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
    std::cout << "YunaWrite Patch: 0.3 About list help;change help list;false&true;mail.txt;setting;setting.txt;Libre plug-ins;green,white,red,blue;del journal protect;chcon change;protect code,virfl;ctrl z;gcc support;code$" << std::endl;
}

class filebody {
public:
    std::string p_name;
    std::string p_content;
};

class buildinto {
public:
    std::vector<filebody> filenumber;
};

void add(buildinto* ptr)
{
    filebody newfl;
    std::cout << "Name:";
    if (!std::getline(std::cin, newfl.p_name))
    {
        std::cin.clear();
    }
    std::cout << "Content:" << std::endl;
    std::cout << "(Press Ctrl z+Enter to finish editing the file)" << std::endl;
    std::string content, truecon;
    while (std::getline(std::cin, content))
    {
        truecon += content + "\n";
    }
    newfl.p_content = truecon;
    ptr->filenumber.push_back(newfl);
}

void showfile(buildinto* ptr)
{
    if (ptr->filenumber.size() == 0)
    {
        std::cout << "No files" << std::endl;
    }
    else {
        for (size_t j = 0; j < ptr->filenumber.size(); j++)
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

static void helpListcode()
{
    std::cout << "  !This shell works best with ASCII input" << std::endl;
    std::cout << "  !For Chinese characters or emoji" << std::endl;
    std::cout << "  !Please use Windows Terminal or CODE outside VS debugger" << std::endl;
    std::cout << std::endl;
    std::cout << "  ?help              View the help memu(any level)" << std::endl;
    std::cout << "  ?cls               Clear screen(any level)" << std::endl;
    std::cout << "  ?sp_help           View the help about plug-in(code)" << std::endl;
    std::cout << std::endl;
    std::cout << "  -adder             Build a folder in the program folder" << std::endl;
    std::cout << "  -addfl             Build a file in the program folder" << std::endl;
    std::cout << "  -patch             View the program's patch history" << std::endl;
    std::cout << "  -quit              Exit the entire program,implemented" << std::endl;
    std::cout << "  -mv                Move a file/folder" << std::endl;
    std::cout << "  -del               Delete a file/folder" << std::endl;
    std::cout << "  -chna              Change a file's name" << std::endl;
    std::cout << "  -chcon             Change a file's content" << std::endl;
    std::cout << "  -find              Search for a file" << std::endl;
    std::cout << "  -support           View the supported file extensions(opexe)" << std::endl;
    std::cout << "  -infor             View the information of YunaWrite" << std::endl;
    std::cout << "  -CODE              Enter to the CODE layer" << std::endl;
    std::cout << "  -look              View the path of YunaWrite(Open Terminal)" << std::endl;
    std::cout << "  -opexe(plug-in)    CODE the file directly" << std::endl;
    std::cout << "  -mail(plug-in)     View the information of mail" << std::endl;
    std::cout << "  -setting(plug-in)  Enable settings" << std::endl;
    std::cout << "  -cpp               Build a .bat/.command/.sh file" << std::endl;
    std::cout << "  -list              List the contents and information of all current files" << std::endl;
    std::cout << "  -virfl             Enter the virtual file system" << std::endl;
}

static void helpListvir()
{
    std::cout << "  !This shell works best with ASCII input" << std::endl;
    std::cout << "  !For Chinese characters or emoji" << std::endl;
    std::cout << "  !Please use Windows Terminal or CODE outside VS debugger" << std::endl;
    std::cout << std::endl;
    std::cout << "  ?help           View the help memu(any level)" << std::endl;
    std::cout << "  ?cls            Clear screen(any level)" << std::endl;
    std::cout << std::endl;
    std::cout << "  -addfl          Build a file" << std::endl;
    std::cout << "  -del            Delete a file" << std::endl;
    std::cout << "  -list           List the contents and information of all current files" << std::endl;
    std::cout << "  -delall         Delete all current files" << std::endl;
    std::cout << "  -chna           Change a file's name" << std::endl;
    std::cout << "  -chcon          Change a file's content" << std::endl;
    std::cout << "  -Ctrl z+Enter(windows)/Ctrl d+Enter(mac/Linux)->Renturn to the code layer" << std::endl;
    std::cout << "  -find           Search for a file and list its content" << std::endl;
}

static void information_os()
{
    std::cout << "==INFORMATION START==" << std::endl;
    std::cout << "  Name:YunaWrite" << std::endl;
    std::cout << "  Creator:Biriks-off" << std::endl;
    std::cout << "  Environment:C++20,VS 2026,Microsoft Windows 10" << std::endl;
    std::cout << "  Version:" << VER << std::endl;
    std::cout << "  Language:English" << std::endl;
    std::cout << "  Create Date(0.0.1): 2026.8.14" << std::endl;
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
    for (int fg = 0; fg < ptr->filenumber.size(); fg++) {
        if (ptr->filenumber[fg].p_name == name) {
            return fg;
        }
    }
    return -1;
}

void changefiles(buildinto* ptr) {
    std::cout << "Old Name:";
    std::string name;
    if (!std::getline(std::cin, name))
    {
        std::cin.clear();
    }
    int ret = orinit(ptr, name);
    if (ret != -1)
    {
        std::cout << "New Name:";
        std::string namenew;
        if (!std::getline(std::cin, namenew))
        {
            std::cin.clear();
        }
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
    if (!std::getline(std::cin, name))
    {
        std::cin.clear();
    }
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
            if (!std::getline(std::cin, namecon))
            {
                std::cin.clear();
            }
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
    if (!std::getline(std::cin, name))
    {
        std::cin.clear();
    }
    int ret = orinit(ptr, name);
    if (ret != -1) {
        ptr->filenumber.erase(ptr->filenumber.begin() + ret);
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
    if (!std::getline(std::cin, name))
    {
        std::cin.clear();
    }
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
        if (!std::getline(std::cin, chooses))
        {
            std::cin.clear();
        }
        if (chooses == "1")
        {
            ptr->filenumber.clear();
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

static void setting_make(yw_setting& fsy)
{
    if (fsy.color_setting == "blue")
    {
        std::cout << "\033[34m";
    }
    else if (fsy.color_setting == "red")
    {
        std::cout << "\033[31m";
    }
    else if (fsy.color_setting == "white")
    {
        std::cout << "\033[37m";
    }
    else if (fsy.color_setting == "green")
    {
        std::cout << "\033[32m";
    }
}

int main()
{
    system("");
    std::cout << "\033[0m";
    yw_setting fsy;
    load_setting(fsy);
    setting_make(fsy);
    buildinto ptr;
    std::cout << "@YUNA YunaWrite " << "[Version: " << VER << " ]" << std::endl;
    std::cout << "Enter \"help\" to view the help memu" << std::endl;
    std::cout << "Language:English" << std::endl;
    std::cout << std::endl;
    static std::string name2, name3, name1, cppcode;
    while (1)
    {
        std::cout << "(@YUNA)CODE$";
        std::string code;
        if (!std::getline(std::cin, code))
        {
            std::cin.clear();
        }
        code.erase(0, code.find_first_not_of(" \t"));
        code.erase(code.find_last_not_of(" \t") + 1);
        if (code.empty()) continue;
        if (code == "adder")
        {
            std::cout << "FOLDER NAME:";
            std::string name1;
            if (!std::getline(std::cin, name1))
            {
                std::cin.clear();
            }
            std::filesystem::create_directories("./" + name1);
        }
        else if (code == "help")
        {
            helpListcode();
        }
        else if (code == "sp_help") sp_help();
        else if (code == "cls")
        {
            clear_OS();
        }
        else if (code == "quit")
        {
            break;
        }
        else if (code == "1" || code == "true") std::cout << "--true(1)\n";
        else if (code == "0" || code == "false") std::cout << "--false(0)\n";
        else if (code == "setting")
        {
            load_setting(fsy);
            setting_make(fsy);
        }
        else if (code == "del")
        {
            std::cout << "Delete Name:";
            std::string name_rm;
            if (!std::getline(std::cin, name_rm))
            {
                std::cin.clear();
            }
            if (std::filesystem::exists(name_rm))
            {
                try {
                    std::filesystem::remove(name_rm);
                    std::cout << "Delete " << "\"" << name_rm << "\"" << "succeeded" << std::endl;
                }
                catch (std::filesystem::filesystem_error& a) {
                    std::cout << "YunaWrite Error:" << a.what() << std::endl;
                }
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
            if (!std::getline(std::cin, name_og_move))
            {
                std::cin.clear();
            }
            std::cout << "Object File / Folder Name:";
            if (!std::getline(std::cin, name_af_move))
            {
                std::cin.clear();
            }
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
            if (!std::getline(std::cin, filename))
            {
                std::cin.clear();
            }
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
            show_mail();
        }
        else if (code == "support")
        {
            support_os();
        }
        else if (code == "cpp")
        {
            std::cerr << "Ctrl z+Enter to exit cpp" << std::endl;
            std::cout << "C++ File Name:";
            std::string cppname;
            if (!std::getline(std::cin, cppname))
            {
                std::cin.clear();
            }
            std::cout << "C++ Version:";
            std::string cppver;
            if (!std::getline(std::cin, cppver))
            {
                std::cin.clear();
            }
            std::cout << "Run File Name:";
            std::string batname;
            if (!std::getline(std::cin, batname))
            {
                std::cin.clear();
            }
            while (1) {
                std::cout << "OS:" << std::endl;
                std::cout << "win" << std::endl;
                std::cout << "mac" << std::endl;
                std::cout << "Linux" << std::endl;
                std::string cppOS;
                if (!std::getline(std::cin, cppOS))
                {
                    std::cin.clear();
                    break;
                }
                if (cppOS == "win")
                {
                    std::ofstream filecpp(batname + ".bat");
                    if (filecpp.is_open())
                    {
                        filecpp << "g++ -std=c++" + cppver + " " + cppname + ".cpp -o " + cppname + ".exe" << std::endl;
                    }
                    filecpp.close();
                    break;
                }
                else if (cppOS == "mac")
                {
                    std::ofstream filecpp(batname + ".command");
                    if (filecpp.is_open())
                    {
                        filecpp << "clang++ -std=c++" + cppver + " " + cppname + ".cpp -o " + cppname << std::endl;
                    }
                    filecpp.close();
                    break;
                }
                else if (cppOS == "Linux")
                {
                    std::ofstream filecpp(batname + ".sh");
                    if (filecpp.is_open())
                    {
                        filecpp << "clang++ -std=c++" + cppver + " " + cppname + ".cpp -o " + cppname << std::endl;
                    }
                    filecpp.close();
                    break;
                }
            }
        }
        else if (code == "hello" || code == "hi" || code == "hey")
        {
            std::cout << "Hello,welcome to YunaWrite" << std::endl;
        }
        else if (code == "virfl")
        {
            while (true)
            {
                std::cout << "(@YUNA)Vircode$";
                std::string codevir;
                if (!std::getline(std::cin, codevir))
                {
                    std::cin.clear();
                    break;
                }
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
                    helpListvir();
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
            if (!std::getline(std::cin, name2))
            {
                std::cin.clear();
            }
            std::cout << "FILE EXTENSION:" << std::endl;
            std::cerr << "TIP:You don't have to write \".\" " << std::endl;
            std::string name3;
            if (!std::getline(std::cin, name3))
            {
                std::cin.clear();
            }
            std::cout << "FILE CONTENT:" << std::endl;
            std::cout << "(Press Ctrl z+Enter to finish editing the file)" << std::endl;
            std::string content;
            std::string true_Content;
            while (std::getline(std::cin, content))
            {
                true_Content += content + "\n";
            }
            std::cin.clear();
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
            while (1)
            {
                std::string choose_chcon;
                std::cout << "Warning:The content will overwrite the original content!" << std::endl;
                std::cout << "        We recommend using opexe:)" << std::endl;
                std::cout << "Are u sure?(y/no)" << std::endl;
                if (!std::getline(std::cin, choose_chcon))
                {
                    std::cin.clear();
                    break;
                }
                if (choose_chcon == "y")
                {
                    std::string name_chcon;
                    std::string name_chcon_content;
                    std::string name_chcon_true;
                    std::cout << "File Name:";
                    if (!std::getline(std::cin, name_chcon))
                    {
                        std::cin.clear();
                    }
                    if (std::filesystem::exists(name_chcon))
                    {
                        try
                        {
                            std::cout << "New Content:" << std::endl;
                            std::cout << "(Press Ctrl z+Enter to finish editing the file)" << std::endl;
                            while (std::getline(std::cin, name_chcon_content))
                            {
                                name_chcon_true += name_chcon_content + "\n";
                            }
                            std::cin.clear();
                            std::ofstream filech(name_chcon);
                            filech << name_chcon_true;
                            filech.close();
                            std::cout << "Change the content about " << "\"" << name_chcon << "\" " << "succeeded" << std::endl;
                            break;
                        }
                        catch (std::filesystem::filesystem_error& o)
                        {
                            std::cerr << "YunaWriteError:" << o.what() << std::endl;
                            break;
                        }
                    }
                    else
                    {
                        std::cerr << "YunaWrite can't find" << "\"" << name_chcon << "\"" << std::endl;
                        break;
                    }
                }
                else if (choose_chcon == "no")
                {
                    break;
                }
                else
                {
                    std::cout << "Please choose y/no" << std::endl;
                }
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
        else if (code == "look") {
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
            if (!std::getline(std::cin, name_Html))
            {
                std::cin.clear();
            }
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
