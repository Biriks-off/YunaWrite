#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <functional>
const std::string VER = "0.5";
static void show_osname()
{
	std::ifstream file_osname("osname.txt");
	if (!file_osname.is_open())
	{
		std::ofstream outname("osname.txt");
		outname << "YunaWrite";
		outname.close();
		file_osname.open("osname.txt");
	}
	std::string line_name;
	while (std::getline(file_osname, line_name))
	{
		std::cout << line_name;
	}
	file_osname.close();
}
static void sp_help()
{
	std::cout << "opexe:" << std::endl;
	std::cout << "   -opexe+Enter+file name     Run the file" << std::endl;
	std::cout << "   -opexe+Enter+Enter         Enter the program directory" << std::endl;
	std::cout << "   -opin(CODE)                Run the .sh/.bat/.command in the ";
	show_osname();
	std::cout << "Environment" << std::endl;
	std::cout << "C/C++:" << std::endl;
	std::cout <<"Please use GCC" << std::endl;
	std::cout << "   -cpp(code)                 Build a .bat/.command/.sh file(cpp)" << std::endl;
	std::cout << "   -cbat(code)                Build a .bat/.command/.sh file(c)" << std::endl;
	std::cout << "   -ft(code)                  Format code of a cpp file(cpp/c)" << std::endl;
	std::cout << "Python:" << std::endl;
	std::cout << "   -py(code)                  Build a .bat/.command/.sh file(py)" << std::endl;
	std::cout << "JavaScript:" << std::endl;
	std::cout << "   -js                        Build a .bat/.command/.sh file(js) " << std::endl;
	std::cout << "Prompt:" << std::endl;
	std::cout << "   -chcon prompt.txt          Change the prompt of code layer" << std::endl;
	std::cout << "Virmpt:" << std::endl;
	std::cout << "   -chcon virmpt.txt          Change the prompt of virfl layer" << std::endl;
	std::cout << "Start:" << std::endl;
	std::cout << "   -chcon start.txt           Change the text of starting" << std::endl;
	std::cout << "Osname:" << std::endl;
	std::cout << "   -chcon osname.txt          Change the name of program" << std::endl;
	std::cout << "setting.txt:" << std::endl;
	std::cout << "   -white                     White words" << std::endl;
	std::cout << "   -blue                      Blue  words" << std::endl;
	std::cout << "   -red                       Red   words" << std::endl;
	std::cout << "   -green                     Green words" << std::endl;
	std::cout << "mail.txt:" << std::endl;
	std::cout << "   -mail(code)                View the mail" << std::endl;
}

static void show_mail()
{
	std::ifstream file_mail("mail.txt");
	if (!file_mail.is_open())
	{
		std::ofstream outmail("mail.txt");
		outmail << "-Version:" << VER << std::endl;
		outmail << "-NEWS:" << std::endl;
		outmail << "   1. We added the \"opin\",you can run .bat/.sh/.command in the YunaWrite environment!" << std::endl;
		outmail << "   2. Change python plug-in,you can run more stably" << std::endl;
		outmail << "   3. Added the list of Contributors,we will remember any contributors:)" << std::endl;
		outmail << "   4. \"ft\" can format cpp/c file by clang" << std::endl;
		outmail << "   5. \"opin\" can run .sh/.bat/.command in this program"<< std::endl;
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
static void show_prompt()
{
	std::ifstream file_prompt("prompt.txt");
	if (!file_prompt.is_open())
	{
		std::ofstream outmpt("prompt.txt");
		outmpt << "Core_Yuna$code->";
		outmpt.close();
		file_prompt.open("prompt.txt");
	}
	std::string line_prompt;
	while (std::getline(file_prompt, line_prompt))
	{
		std::cout << line_prompt;
	}
	file_prompt.close();
}
static void show_virmpt()
{
	std::ifstream file_virmpt("virmpt.txt");
	if (!file_virmpt.is_open())
	{
		std::ofstream outvir("virmpt.txt");
		outvir << "Core_Yuna$code$Vircode->";
		outvir.close();
		file_virmpt.open("virmpt.txt");
	}
	std::string line_virmpt;
	while (std::getline(file_virmpt, line_virmpt))
	{
		std::cout << line_virmpt;
	}
	file_virmpt.close();
}
static void show_start()
{
	std::ifstream file_start("start.txt");
	if (!file_start.is_open())
	{
		std::ofstream outstart("start.txt");
		outstart << "@YUNA YunaWrite "
			<< "[Version: " << VER << " ]" << std::endl;
		outstart << "Enter \"help\" to view the help menu" << std::endl;
		outstart << "Language:English" << std::endl;
		outstart.close();
		file_start.open("start.txt");
	}
	std::string line_start;
	while (std::getline(file_start, line_start))
	{
		std::cout << line_start << std::endl;

	}
	std::cout << std::endl;
	file_start.close();
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
		if (line_setting.empty())
			continue;
		if (!line_setting.empty() && line_setting.back() == '\r')
			line_setting.pop_back();
		if (line_num == 0)
		{
			if (line_setting == "blue")
				fsy.color_setting = "blue";
			else if (line_setting == "red")
				fsy.color_setting = "red";
			else if (line_setting == "white")
				fsy.color_setting = "white";
			else
				fsy.color_setting = "green";
		}
		line_num++;
	}
	setting_file.close();
}
class filebody
{
public:
	std::string p_name;
	std::string p_content;
};

class buildinto
{
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
	std::cout << "(Press Ctrl z/d +Enter to finish editing the file)" << std::endl;
	std::string content, truecon;
	while (std::getline(std::cin, content))
	{
		if (content == "OVER_ABOUT_STOP") { break; }
		truecon += content + "\n";
	}
	std::cin.clear();
	newfl.p_content = truecon;
	ptr->filenumber.push_back(newfl);
}

void showfile(buildinto* ptr)
{
	if (ptr->filenumber.size() == 0)
	{
		std::cout << "No files" << std::endl;
	}
	else
	{
		for (size_t j = 0; j < ptr->filenumber.size(); j++)
		{
			std::cout << "=======================VIRFL=======================" << std::endl;
			std::cout << "[" << j << "]" << std::endl;
			std::cout << "Name:" << ptr->filenumber[j].p_name << std::endl;
			std::cout << "Content:" << std::endl;
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
	std::cout << "  !Ctrl+z(win),Ctrl+d(mac/Linux)   back/stop writing" << std::endl;
	std::cout << std::endl;
	std::cout << "  *patch             View the program's patch history" << std::endl;
	std::cout << "  *crb               View the Contributors of ";
	show_osname();
	std::cout << "\n";
	std::cout << "  *ctrl+c            Exit ";
	show_osname();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "  ?help              View the help menu(any level)" << std::endl;
	std::cout << "  ?cls               Clear screen(any level)" << std::endl;
	std::cout << "  ?sp_help           View the help about plug-in(code)" << std::endl;
	std::cout << "  ?soft              The help of soft key" << std::endl;
	std::cout << std::endl;
	std::cout << "  -adder             Build a folder in the program folder" << std::endl;
	std::cout << "  -addfl             Build a file in the program folder" << std::endl;
	std::cout << "  -mv                Move a file/folder" << std::endl;
	std::cout << "  -del               Delete a file/folder" << std::endl;
	std::cout << "  -delall            Delete all plug-ins(YunaWrite,Does not include the compiler)" << std::endl;
	std::cout << "  -chcon             Change a file's content(The content will completely cover the previous one)" << std::endl;
	std::cout << "  -find              Search for a file/folder" << std::endl;
	std::cout << "  -support           View the supported file extensions(opexe)" << std::endl;
	std::cout << "  -infor             View the information of program" << std::endl;
	std::cout << "  -look              View the path of program(Open Terminal)" << std::endl;
	std::cout << "  -opexe(plug-in)    open the file/folder directly" << std::endl;
	std::cout << "  -opin(plug-in)     open the file in the ";
	show_osname();
	std::cout << "  Environment,";
	std::cout << "run .sh/.bat/.command in the " << std::endl;
	show_osname();
	std::cout << "  Environment" << std::endl;
	std::cout << "  -ft(plug-in)      Format code of a cpp file (cpp/c) by clang" << std::endl;
	std::cout << "  -mail(plug-in)     View the information of mail" << std::endl;
	std::cout << "  -setting(plug-in)  Enable settings" << std::endl;
	std::cout << "  -list              List the contents and information of all current files" << std::endl;
	std::cout << "  -virfl             Enter the virtual file system" << std::endl;
}

static void helpListvir()
{
	std::cout << "  !This shell works best with ASCII input" << std::endl;
	std::cout << "  !For Chinese characters or emoji" << std::endl;
	std::cout << "  !Please use Windows Terminal or CODE outside VS debugger" << std::endl;
	std::cout << std::endl;
	std::cout << "  ?help           View the help menu(any level)" << std::endl;
	std::cout << "  ?cls            Clear screen(any level)" << std::endl;
	std::cout << std::endl;
	std::cout << "  -addfl          Build a file" << std::endl;
	std::cout << "  -del            Delete a file" << std::endl;
	std::cout << "  -list           List the contents and information of all current files" << std::endl;
	std::cout << "  -delall         Delete all current files" << std::endl;
	std::cout << "  -chna           Change a file's name" << std::endl;
	std::cout << "  -chcon          Change a file's content" << std::endl;
	std::cout << "  -Ctrl z+Enter(windows)/Ctrl d+Enter(mac/Linux)->Return to the code layer" << std::endl;
	std::cout << "  -find           Search for a file and list its content" << std::endl;
}
static void support_os()
{
	std::cout << R"(YunaWrite Support Suffix:
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
	std::cout << std::endl;
}
static void Patch()
{
	show_osname();
	std::cout << " Patch: 0.0.1 About the file space issue" << std::endl;    show_osname();
	std::cout << " Patch: 0.0.2 About create a new file - cls" << std::endl;
	show_osname();
	std::cout << " Patch: 0.0.3 About create a new file(std::cin name? content ....)" << std::endl;
	show_osname();
	std::cout << " Patch: 0.0.4 About CODE html,cpp" << std::endl;
	show_osname();
	std::cout << " Patch: 0.0.5 About HELP,back,Patch,cerr about else at code layer,copyright notice" << std::endl;
	show_osname();
	std::cout << " Patch: 0.0.6 About content loop issue,enter make else issue" << std::endl;
	show_osname();
	std::cout << " Patch: 0.0.7 About opexe safety,virfl layer,patch in code layer,cpp safety,infor" << std::endl;
	show_osname();
	std::cout << " Patch: 0.1 About Github Change,YunaWrite,0.1.ver" << std::endl;
	show_osname();
	std::cout << " Patch: 0.2 About CODE del;Code move,chcon,find,list,mail;android;CODE plus Mail,CODE" << std::endl;
	show_osname();
	std::cout << " Patch: 0.3 About list help;change help list;false&true;mail.txt;setting;setting.txt;Libre plug-ins;green,white,red,blue;del journal protect;chcon change;protect code,virfl;ctrl z;gcc support;code$" << std::endl;
	show_osname();
	std::cout << " Patch: 0.4 About start.txt;prompt.txt;virmpt.txt;osname.txt;Cpython;cbat;node.js;setting;help change;picture of YW;ctrl d;OVER_ABOUT_STOP;mv change;delall code" << std::endl;
	show_osname();
	std::cout << " Patch: 0.5 About del space(0.4);change Python;ex_Node.js,crb,format,clang,std::map<>,lambda void;change(fix),infor change.opin(yw_environment)" << std::endl;
}

int orinit(buildinto* ptr, std::string name)
{
	for (int fg = 0; fg < ptr->filenumber.size(); fg++)
	{
		if (ptr->filenumber[fg].p_name == name)
		{
			return fg;
		}
	}
	return -1;
}

void changefiles(buildinto* ptr)
{
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
		std::cout << "Not found" << std::endl;
	}
}

void changecontent(buildinto* ptr)
{
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
		while (1)
		{
			if (!std::getline(std::cin, namecon))
			{
				std::cin.clear();
			}
			if (namecon == "OVER_ABOUT_STOP" || namecon == "\x1A")
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
		std::cout << "Not found" << std::endl;
	}
}

void delfile(buildinto* ptr)
{
	std::cout << "Delete(file's name):";
	std::string name;
	if (!std::getline(std::cin, name))
	{
		std::cin.clear();
	}
	int ret = orinit(ptr, name);
	if (ret != -1)
	{
		ptr->filenumber.erase(ptr->filenumber.begin() + ret);
		std::cout << "\"" << name << ".word"
			<< "\"   "
			<< "delete succeeded:)" << std::endl;
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
}

void searchf(buildinto* ptr)
{
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
		std::cout << "Not found" << std::endl;
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
		else
		{
			std::cout << "Not found" << std::endl;
		}
	}
}

static void clear_OS()
{
#if defined(_WIN32)
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
std::string prompt_str = "(@YUNA)CODE$";
std::string virmpt_str = "(@YUNA)Vircode$";
std::string osname_str = "YunaWrite";
static void load_prompt_str() {
	std::ifstream file("prompt.txt");
	if (file.is_open()) {
		std::getline(file, prompt_str);
		if (!prompt_str.empty() && prompt_str.back() == '\r') prompt_str.pop_back();
		file.close();
	}
}

static void load_virmpt_str() {
	std::ifstream file("virmpt.txt");
	if (file.is_open()) {
		std::getline(file, virmpt_str);
		if (!virmpt_str.empty() && virmpt_str.back() == '\r') virmpt_str.pop_back();
		file.close();
	}
}
static void load_osname_str() {
	std::ifstream file("osname.txt");
	if (file.is_open()) {
		std::getline(file, osname_str);
		if (!osname_str.empty() && osname_str.back() == '\r') osname_str.pop_back();
		file.close();
	}
}
static void information_os()
{
	std::cout << "==INFORMATION START==" << std::endl;
	std::cout << "  Name:";
	show_osname();
	std::cout << std::endl;
	std::cout << "  Creator:Biriks-off" << std::endl;
	std::cout << "  Environment:C++20,VS 2026,Microsoft Windows 10,MSVC" << std::endl;
	std::cout << "  Version:" << VER << std::endl;
	std::cout << "  Language:English" << std::endl;
	std::cout << "  Create Date(YunaIDE 0.0.1): 2026.8.14" << std::endl;
	std::cout << "==INFORMATION END==" << std::endl;
}
static void start_look()
{
	system("");
	std::cout << "\033[0m";
	yw_setting fsy;
	load_setting(fsy);
	setting_make(fsy);
	show_start();
	load_prompt_str();
	load_virmpt_str();
	buildinto ptr;
	static std::string name2, name3, name1, cppcode;
}

void delall_os()
{
	try
	{
		std::filesystem::remove("setting.txt");
		std::filesystem::remove("mail.txt");
		std::filesystem::remove("prompt.txt");
		std::filesystem::remove("virmpt.txt");
		std::filesystem::remove("start.txt");
		std::filesystem::remove("osname.txt");
		std::cout << "Delall succeeded" << std::endl;
	}
	catch (std::filesystem::filesystem_error& a)
	{
		std::cout << "Error:" << a.what() << std::endl;
	}

}
static yw_setting fsy;
void adder_os()
{
	std::cout << "FOLDER NAME:";
	std::string name1;
	if (!std::getline(std::cin, name1))
	{
		std::cin.clear();
	}
	std::filesystem::create_directories("./" + name1);
}
static void setting_os( )
{
	load_setting(fsy);
	setting_make(fsy);
	load_prompt_str();
	load_virmpt_str();
	load_osname_str();

	std::cout << "Setting succeeded" << std::endl;
}
void del_os()
{
	std::cout << "Delete Name:";
	std::string name_rm;
	if (!std::getline(std::cin, name_rm))
	{
		std::cin.clear();
	}
	if (std::filesystem::exists(name_rm))
	{
		try
		{
			std::filesystem::remove(name_rm);
			std::cout << "Delete "
				<< "\"" << name_rm << "\""
				<< "succeeded" << std::endl;
		}
		catch (std::filesystem::filesystem_error& a)
		{
			std::cout << "Error:" << a.what() << std::endl;
		}
	}
	else
	{
		show_osname();
		std::cerr << " can't find " << name_rm << std::endl;
	}
}
void mv_os()
{
	std::string source, dest_folder;
	std::cout << "Source: ";
	std::getline(std::cin, source);
	source.erase(0, source.find_first_not_of(" \t\r\n"));
	source.erase(source.find_last_not_of(" \t\r\n") + 1);

	std::cout << "Folder: ";
	std::getline(std::cin, dest_folder);
	dest_folder.erase(0, dest_folder.find_first_not_of(" \t\r\n"));
	dest_folder.erase(dest_folder.find_last_not_of(" \t\r\n") + 1);
	std::filesystem::path full_path = std::filesystem::path(dest_folder) / source;

	try
	{
		std::filesystem::rename(source, full_path);
		std::cout << "Moved " << source << " -> " << full_path.string() << " succeeded" << std::endl;
	}
	catch (std::filesystem::filesystem_error& a)
	{
		show_osname();
		std::cout << "Error: " << a.what() << std::endl;
	}
}
void true_os()
{
	std::cout << "--true(1)" << std::endl;
}
void false_os()
{
	std::cout << "--false(0)" << std::endl;
}
void find_os()
{
	std::string filename;
	std::cout << "File Name:";
	if (!std::getline(std::cin, filename))
	{
		std::cin.clear();
	}
	if (std::filesystem::exists(filename))
	{
		try
		{
			std::cout << "File Name:" << filename << std::endl;
			std::cout << "Content:" << std::endl;
			std::cout << std::endl;
			std::ifstream file_find(filename);
			std::string line_find;
			while (std::getline(file_find, line_find)) {
				std::cout << line_find << std::endl;
			}

			file_find.close();
			std::cout << std::endl;
		}
		catch (std::filesystem::filesystem_error& a)
		{
			show_osname();
			std::cout << "Error:" << a.what() << std::endl;
		}
	}
	else
	{
		show_osname();
		std::cout << " can't find"
			<< "\"" << filename << "\"" << std::endl;
	}
}
void cpp_os()
{
	std::cerr << "Ctrl z/d+Enter to exit cpp" << std::endl;
	std::cout << "C++ File Name:";
	std::string cppname;
	if (!std::getline(std::cin, cppname))
	{
		std::cin.clear();
	}
	std::cout << "C++ Version(number):";
	std::string cppver;
	if (!std::getline(std::cin, cppver))
	{
		std::cin.clear();
	}
	std::cout << "Run File Name(No suffix):";
	std::string batname;
	if (!std::getline(std::cin, batname))
	{
		std::cin.clear();
	}
	while (1)
	{
		std::cout << "Choose OS:" << std::endl;
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
				filecpp << "g++ -std=c++" + cppver + " " + cppname + ".cpp -o " + cppname << std::endl;
			}
			filecpp.close();
			break;
		}
	}
}
void cbat_os()
{
	std::cerr << "Ctrl z/d+Enter to exit cbat" << std::endl;
	std::cout << ".C File Name(No suffix):";
	std::string cname;
	if (!std::getline(std::cin, cname))
	{
		std::cin.clear();
	}
	std::cout << "C Version(number):";
	std::string cver;
	if (!std::getline(std::cin, cver))
	{
		std::cin.clear();
	}
	std::cout << "Run File Name(No suffix):";
	std::string cbatname;
	if (!std::getline(std::cin, cbatname))
	{
		std::cin.clear();
	}
	while (1)
	{
		std::cout << "Choose OS:" << std::endl;
		std::cout << "win" << std::endl;
		std::cout << "mac" << std::endl;
		std::cout << "Linux" << std::endl;
		std::string cOS;
		if (!std::getline(std::cin, cOS))
		{
			std::cin.clear();
			break;
		}
		if (cOS == "win")
		{
			std::ofstream filec(cbatname + ".bat");
			if (filec.is_open())
			{
				filec << "gcc -std=c" + cver + " " + cname + ".c -o " + cname + ".exe" << std::endl;
			}
			filec.close();
			break;
		}
		else if (cOS == "mac")
		{
			std::ofstream filec(cbatname + ".command");
			if (filec.is_open())
			{
				filec << "clang -std=c" + cver + " " + cname + ".c -o " + cname << std::endl;
			}
			filec.close();
			break;
		}
		else if (cOS == "Linux")
		{
			std::ofstream filec(cbatname + ".sh");
			if (filec.is_open())
			{
				filec << "gcc -std=c" + cver + " " + cname + ".c -o " + cname << std::endl;
			}
			filec.close();
			break;
		}
	}
}
void js_os()
{
	std::cerr << "Ctrl z/d+Enter to exit js" << std::endl;
	std::cout << "JS File Name(No suffix):";
	std::string jsname;
	if (!std::getline(std::cin, jsname))
	{
		std::cin.clear();
	}

	while (1)
	{
		std::cout << "Choose OS:" << std::endl;
		std::cout << "win" << std::endl;
		std::cout << "mac" << std::endl;
		std::cout << "Linux" << std::endl;
		std::string jsOS;
		if (!std::getline(std::cin, jsOS))
		{
			std::cin.clear();
			break;
		}
		if (jsOS == "win")
		{
			std::ofstream filejs(jsname + ".bat");
			if (filejs.is_open())
			{
				filejs << "node " + jsname + ".js" << std::endl;
			}
			filejs.close();
			break;
		}
		else if (jsOS == "mac")
		{
			std::ofstream filejs(jsname + ".command");
			if (filejs.is_open())
			{
				filejs << "node " + jsname + ".js" << std::endl;
			}
			filejs.close();
			break;
		}
		else if (jsOS == "Linux")
		{
			std::ofstream filejs(jsname + ".sh");
			if (filejs.is_open())
			{
				filejs << "node " + jsname + ".js" << std::endl;
			}
			filejs.close();
			break;
		}
	}
}
void py_os()
{
	std::cerr << "Ctrl z/d+Enter to exit py" << std::endl;
	std::cout << "Python File Name(No suffix):";
	std::string pyname;
	if (!std::getline(std::cin, pyname))
	{
		std::cin.clear();
	}
	std::cout << "Python Version(number):";
	std::cout << "If u use Windows,please press Enter..." << std::endl;
	std::string pyver;
	if (!std::getline(std::cin, pyver))
	{
		std::cin.clear();
	}

	while (1)
	{
		std::cout << "Choose OS:" << std::endl;
		std::cout << "win" << std::endl;
		std::cout << "mac" << std::endl;
		std::cout << "Linux" << std::endl;
		std::string pyOS;
		if (!std::getline(std::cin, pyOS))
		{
			std::cin.clear();
			break;
		}
		if (pyOS == "win")
		{
			std::ofstream filepy(pyname + ".bat");
			if (filepy.is_open())
			{
				filepy << "py " + pyname + ".py" << std::endl;
			}
			filepy.close();
			break;
		}
		else if (pyOS == "mac")
		{
			std::ofstream filepy(pyname + ".command");
			if (filepy.is_open())
			{
				filepy << "python" + pyver + " " + pyname + ".py" << std::endl;
			}
			filepy.close();
			break;
		}
		else if (pyOS == "Linux")
		{
			std::ofstream filepy(pyname + ".sh");
			if (filepy.is_open())
			{
				filepy << "python" + pyver + " " + pyname + ".py" << std::endl;
			}
			filepy.close();
			break;
		}
	}
}
void addfl_os()
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
	std::cout << "(Press Ctrl z/d+Enter to finish editing the file)" << std::endl;
	std::string content;
	std::string true_Content;
	while (std::getline(std::cin, content))
	{
		if (content == "OVER_ABOUT_STOP") { break; }
		true_Content += content + "\n";
	}
	std::cin.clear();
	std::filesystem::path theFile = std::filesystem::current_path();
	std::filesystem::path theBuild = theFile / (name2 + "." + name3);
	std::filesystem::create_directories(theBuild.parent_path());
	std::ofstream file(theBuild);
	if (file.is_open())
	{
		file << true_Content;
		file.close();
	}
}
void chcon_code()
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
			std::cout << "(Press Ctrl z/d+Enter to finish editing the file)" << std::endl;
			while (std::getline(std::cin, name_chcon_content))

			{
				if (name_chcon_content == "OVER_ABOUT_STOP") { break; }
				name_chcon_true += name_chcon_content + "\n";
			}
			std::cin.clear();
			std::ofstream filech(name_chcon);
			filech << name_chcon_true;
			filech.close();
			std::cout << "Change the content of "
				<< "\"" << name_chcon << "\" "
				<< "succeeded" << std::endl;

		}
		catch (std::filesystem::filesystem_error& o)
		{
			show_osname();
			std::cerr << "Error:" << o.what() << std::endl;
			return;
		}
	}
	else
	{
		show_osname();
		std::cerr << " can't find"
			<< "\"" << name_chcon << "\"" << std::endl;

	}
}
void list_code()
{
	try
	{
		for (const auto& entry : std::filesystem::directory_iterator("."))
		{
			std::cout << entry.path().filename().string() << std::endl;
		}
	}
	catch (std::filesystem::filesystem_error& listfile)
	{
		show_osname();
		std::cout << "Error:" << listfile.what() << std::endl;
	}
}
void opexe_os()
{
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
void look_os()
{
#if defined(_WIN32)
	system("start cmd");
#elif defined(__APPLE__)
	system("open -a Terminal .");
#elif defined(__linux__)
	system("x-terminal-emulator &");
#endif
}
void hello_os()
{
	std::cout <<"Hello,welcome to YunaWrite" << std::endl;
}
void soft()
{
	std::cout << "  !This shell works best with ASCII input" << std::endl;
	std::cout << "  !For Chinese characters or emoji" << std::endl;
	std::cout << "  !Please use Windows Terminal or CODE outside VS debugger" << std::endl;
	std::cout << "    - OVER_ABOUT_STOP    Stop writing" << std::endl;
	std::cout << "    - back               Enter CODE" << std::endl;
	std::cout << "    - quit               Exit " ;
	show_osname();
	std::cout << "(CODE)" << std::endl;
	std::cout << std::endl;
}
void  crb()
{
	std::cout << "-Contributors:" << std::endl;
	std::cout << "1.Biriks-off" << std::endl;
	std::cout << "2.Tamon" << std::endl;
}
void opin()
{
	std::string name_ft;
	std::cout << "File Name:";
	if (!std::getline(std::cin, name_ft))
	{
		std::cin.clear();
	}
	std::string ft_ter;
	system(name_ft.c_str());

	std::cout << "opin (OK)--@";
	show_osname();
	std::cout << std::endl;
}
void ft()
{
	std::string name_ft;
	std::cout << "File Name(No suffix):";
	if (!std::getline(std::cin, name_ft))
	{
		std::cin.clear();
	}
	std::string ft_ter= "clang-format -i " + name_ft + ".cpp";
	system(ft_ter.c_str());

	std::cout << "opin (OK)--@";
	show_osname();
	std::cout << std::endl;
}
int main()
{
	bool running_now = true;
	std::cout << "\033[0m";
	buildinto ptr;
	load_setting(fsy);
	setting_make(fsy);
	show_start();
	load_prompt_str();
	load_virmpt_str();

	std::map <std::string, std::function<void()>> codemap;
	std::map <std::string, std::function<void()>> codevir;
	codemap["help"] = helpListcode;
	codemap["infor"] =information_os;
	codemap["mail"] = show_mail;
	codemap["cls"] = clear_OS;
	codemap["sp_help"] = sp_help;
	codemap["patch"] = Patch;
	codemap["support"] = support_os;
	codemap["delall"] = delall_os;
	codemap["adder"] = adder_os;
	codemap["addfl"] = addfl_os;
	codemap["setting"] = setting_os;
	codemap["del"] = del_os;
	codemap["mv"] = mv_os;
	codemap["1"] =true_os ;
	codemap["true"] = true_os;
	codemap["false"] = false_os;
	codemap["0"] = false_os;
	codemap["chcon"] = chcon_code;
	codemap["opexe"] = opexe_os;
	codemap["look"] = look_os;
	codemap["list"] = list_code;
	codemap["cpp"] = cpp_os;
	codemap["cbat"] = cbat_os;
	codemap["py"] = py_os;
	codemap["js"] = js_os;
	codemap["find"]=find_os;
	codemap["hello"] = hello_os;
	codemap["soft"] = soft;
	codemap["crb"] = crb;
	codemap["quit"] = [&]() {running_now = false;};
	codemap["opin"] = opin;
	codemap["ft"] = ft;


	codevir["cls"]   =clear_OS ;
	codevir["help"]  =helpListvir ;
	codevir["addfl"] = [&]() {add(&ptr);};
	codevir["del"]   = [&]() {delfile(&ptr);};
	codevir["chcon"] = [&]() {changecontent(&ptr);};
	codevir["chna"]  = [&]() {changefiles(&ptr);};
	codevir["delall"]= [&]() {delallfiles(&ptr);};
	codevir["find"]  = [&]() {searchf(&ptr);};
	codevir["list"]  = [&]() {showfile(&ptr);};
	
	while (running_now)
	{
		try {
			show_prompt();
			std::string code;
			if (!std::getline(std::cin, code)) { std::cin.clear(); }
			code.erase(0, code.find_first_not_of(" \t"));
			code.erase(code.find_last_not_of(" \t") + 1);
			if (code.empty()) continue;


			auto it = codemap.find(code);
			if (it != codemap.end())
			{
				it->second();
			}
			else if (code == "virfl")
			{
				while (true)
				{
					show_virmpt();
					std::string vir_input;
					if (!std::getline(std::cin, vir_input)) { std::cin.clear(); break; }
					vir_input.erase(0, vir_input.find_first_not_of(" \t"));
					vir_input.erase(vir_input.find_last_not_of(" \t") + 1);
					if (vir_input.empty()) continue;

					auto vit = codevir.find(vir_input);
					if (vit != codevir.end())
					{
						vit->second();
					}
					else if (vir_input == "back")
					{
						std::cout << "Back CODE" << std::endl;
						break;
					}
					else
					{
						show_osname();
						std::cerr << " can't process \"" << vir_input << "\"" << std::endl;
					}
				}
			}
			else
			{
				show_osname();
				std::cerr << " can't process \"" << code << "\"" << std::endl;
			}
		}
		catch (std::system_error& a)
		{
			std::cout <<"YunaWrite(system error):" <<a.what()<< std::endl;
		}
	}
}