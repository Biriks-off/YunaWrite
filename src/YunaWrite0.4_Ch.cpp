#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

const std::string VER = "0.4";

static void sp_help()
{
	std::cout << "opexe:" << std::endl;
	std::cout << "   -opexe+Enter+文件名     运行文件" << std::endl;
	std::cout << "   -opexe+Enter+回车      进入程序目录" << std::endl;
	std::cout << "C/C++:" << std::endl;
	std::cout << "   -cpp(code)             生成 .bat/.command/.sh 文件(cpp)" << std::endl;
	std::cout << "   -cbat(code)            生成 .bat/.command/.sh 文件(c)" <<std::endl;
	std::cout << "Python:" <<std::endl;
	std::cout << "   -py(code)              生成 .bat/.command/.sh 文件(py)" <<std::endl;
    std::cout << "JavaScript:" <<std::endl;
     std::cout << "   -js                    生成 .bat/.command/.sh 文件(js)" <<std::endl;
     std::cout << "Prompt:" << std::endl;
     std::cout << "   -chcon prompt.txt      修改 CODE 层提示符" << std::endl;
     std::cout << "Virmpt:" << std::endl;
     std::cout << "   -chcon virmpt.txt      修改虚拟文件层提示符" << std::endl;
     std::cout << "Start:" << std::endl;
     std::cout << "   -chcon start.txt       修改启动文字" << std::endl;
     std::cout << "Osname:" << std::endl;
     std::cout << "   -chcon osname.txt      修改程序名称" << std::endl;
	std::cout << "setting.txt:" << std::endl;
	std::cout << "   -white                  白色文字" << std::endl;
	std::cout << "   -blue                   蓝色文字" << std::endl;
	std::cout << "   -red                    红色文字" << std::endl;
	std::cout << "   -green                  绿色文字" << std::endl;
	std::cout << "mail.txt:" << std::endl;
	std::cout << "   -mail(code)             查看邮件" << std::endl;
}

static void show_mail()
{
	std::ifstream file_mail("mail.txt");
	if (!file_mail.is_open())
	{
		std::ofstream outmail("mail.txt");
		outmail << "-版本:" << VER << std::endl;
		outmail << "-贡献者:" << std::endl;
		outmail << "1. Biriks-off" << std::endl;
		outmail << "2. Tamon" << std::endl;
		outmail << "-新闻:" << std::endl;
		outmail << "   1. 神经系统: 通过 txt 修改任何东西 (setting/prompt/virmpt/start/osname)。无需重启。只需按'setting'。" << std::endl;
		outmail << "   2. 11个接口: 从 GCC 到 Python 和 node.js。四个编译器引擎在这里!" << std::endl;
		outmail << "   3. 历史是你的: 即使补丁也可以被修改。你的系统名是什么? Linux? MS-DOS? 由你决定。" << std::endl;
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
		outmpt <<  "Core_Yuna$code->" ;
		outmpt.close();
		file_prompt.open("prompt.txt");
	}
	std::string line_prompt;
	while (std::getline(file_prompt, line_prompt))
	{
		std::cout << line_prompt ;
	}
	file_prompt.close();
}

static void show_osname()
{
	std::ifstream file_osname("osname.txt");
	if (!file_osname.is_open())
	{
		std::ofstream outname("osname.txt");
		outname <<  "YunaWrite";
		outname.close();
		file_osname.open("osname.txt");
	}
	std::string line_name;
	while (std::getline(file_osname, line_name))
	{
		std::cout << line_name ;
	}
	file_osname.close();
}
static void show_virmpt()
{
	std::ifstream file_virmpt("virmpt.txt");
	if (!file_virmpt.is_open())
	{
		std::ofstream outvir("virmpt.txt");
		outvir <<  "Core_Yuna$code$Vircode->" ;
		outvir.close();
		file_virmpt.open("virmpt.txt");
	}
	std::string line_virmpt;
	while (std::getline(file_virmpt, line_virmpt))
	{
		std::cout << line_virmpt ;
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
			  << "[版本: " << VER << " ]"<< std::endl;
	outstart << "输入 \"help\" 查看帮助菜单" << std::endl;
	outstart << "语言: 简体中文" << std::endl; 
		outstart.close();
		file_start.open("start.txt");
	}
	std::string line_start;
	while (std::getline(file_start, line_start))
	{
		std::cout << line_start <<std::endl;
		
	}
	std::cout<<std::endl;
	file_start.close();
}
struct yw_setting
{
	std::string color_setting = "white";
};

static void load_setting(yw_setting &fsy)
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

void add(buildinto *ptr)
{
	filebody newfl;
	std::cout << "文件名:";
	if (!std::getline(std::cin, newfl.p_name))
	{
		std::cin.clear();
	}
	std::cout << "内容:" << std::endl;
	std::cout << "(按 Ctrl z/d +回车 结束文件编辑)" << std::endl;
	std::string content, truecon;
	while (std::getline(std::cin, content))
	{
		if (content == "OVER_ABOUT_STOP") { break; }
		truecon += content + "\n";
	}
	newfl.p_content = truecon;
	ptr->filenumber.push_back(newfl);
}

void showfile(buildinto *ptr)
{
	if (ptr->filenumber.size() == 0)
	{
		std::cout << "没有文件" << std::endl;
	}
	else
	{
		for (size_t j = 0; j < ptr->filenumber.size(); j++)
		{
			std::cout << "=======================虚拟文件系统=======================" << std::endl;
			std::cout << "[" << j << "]" << std::endl;
			std::cout << "名称:" << ptr->filenumber[j].p_name << std::endl;
			std::cout << "内容:" << std::endl;
			std::cout << "===================================================" << std::endl;
			std::cout << ptr->filenumber[j].p_content << std::endl;
			std::cout << "===================================================" << std::endl;
			std::cout << "" << std::endl;
		}
	}
}

static void helpListcode()
{
	std::cout << "  !本工具在 ASCII 输入下表现最佳" << std::endl;
	std::cout << "  !如需输入中文或表情符号，请使用 Windows 终端" << std::endl;
	std::cout << "  !或在 Visual Studio 调试器外部运行" << std::endl;
	std::cout << std::endl;
	std::cout << "  *patch              查看程序的补丁历史" << std::endl;
	std::cout<<std::endl;
	std::cout << "  ?help               查看帮助菜单(任意层级)" << std::endl;
	std::cout << "  ?cls                清屏(任意层级)" << std::endl;
	std::cout << "  ?sp_help            查看关于插件的帮助(代码层)" << std::endl;
	std::cout << std::endl;
	std::cout << "  -adder              在程序目录下创建文件夹" << std::endl;
	std::cout << "  -addfl              在程序目录下创建文件" << std::endl;
	std::cout << "  -quit               退出整个程序,已实现" << std::endl;
	std::cout << "  -mv                 移动/重命名文件或文件夹" << std::endl;
	std::cout << "  -del                删除文件或文件夹" << std::endl;
	std::cout <<"  -delall             删除所有插件(YunaWrite,不包含编译器)"<<std::endl;
	std::cout << "  -chna               修改文件名" << std::endl;
	std::cout << "  -chcon              修改文件内容(内容将完全覆盖之前的内容)" << std::endl;
	std::cout << "  -find               查找文件/文件夹" << std::endl;
	std::cout << "  -support            查看支持的文件后缀(opexe)" << std::endl;
	std::cout << "  -infor              查看程序信息" << std::endl;
	std::cout << "  -CODE               进入 CODE 层" << std::endl;
	std::cout << "  -look               查看程序路径(打开终端)" << std::endl;
	std::cout << "  -opexe(plug-in)     直接打开文件/文件夹" << std::endl;
	std::cout << "  -mail(plug-in)      查看邮件信息" << std::endl;
	std::cout << "  -setting(plug-in)   启用设置" << std::endl;
	std::cout << "  -list               列出所有当前文件的内容和信息" << std::endl;
	std::cout << "  -virfl              进入虚拟文件系统" << std::endl;
}

static void helpListvir()
{
	std::cout << "  !本工具在 ASCII 输入下表现最佳" << std::endl;
	std::cout << "  !如需输入中文或表情符号，请使用 Windows 终端" << std::endl;
	std::cout << "  !或在 Visual Studio 调试器外部运行" << std::endl;
	std::cout << std::endl;
	std::cout << "  ?help               查看帮助菜单(任意层级)" << std::endl;
	std::cout << "  ?cls                清屏(任意层级)" << std::endl;
	std::cout << std::endl;
	std::cout << "  -addfl              创建文件" << std::endl;
	std::cout << "  -del                删除文件" << std::endl;
	std::cout << "  -list               列出所有当前文件的内容和信息" << std::endl;
	std::cout << "  -delall             删除所有当前文件" << std::endl;
	std::cout << "  -chna               修改文件名" << std::endl;
	std::cout << "  -chcon              修改文件内容" << std::endl;
	std::cout << "  -Ctrl z+回车(Windows)/Ctrl d+回车(Mac/Linux)->返回 CODE 层" << std::endl;
	std::cout << "  -find               查找文件并列出其内容" << std::endl;
}
static void support_os()
{
	std::cout << R"(YunaWrite 支持的后缀:
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
    (以及所有常见的媒体/文档，由关联程序打开)

    Linux
    .desktop .sh .bash
    .zsh .csh .py
    .pl .rb .CODE
    .bin .appimage
    (以及无后缀但具有执行权限的二进制文件；媒体/文档同样由关联程序打开))";
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
	std::cout << " Patch:  0.4 About start.txt;prompt.txt;virmpt.txt;osname.txt;Cpython;cbat;node.js;setting;help change;picture of YW;ctrl d;OVER_ABOUT_STOP;mv change;delall code" << std::endl;
}

int orinit(buildinto *ptr, std::string name)
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

void changefiles(buildinto *ptr)
{
	std::cout << "旧名称:";
	std::string name;
	if (!std::getline(std::cin, name))
	{
		std::cin.clear();
	}
	int ret = orinit(ptr, name);
	if (ret != -1)
	{
		std::cout << "新名称:";
		std::string namenew;
		if (!std::getline(std::cin, namenew))
		{
			std::cin.clear();
		}
		ptr->filenumber[ret].p_name = namenew;
		std::cout << "修改成功" << std::endl;
	}
	else
	{
		std::cout << "未找到" << std::endl;
	}
}

void changecontent(buildinto *ptr)
{
	std::cout << "名称:";
	std::string name;
	if (!std::getline(std::cin, name))
	{
		std::cin.clear();
	}
	int ret = orinit(ptr, name);
	if (ret != -1)
	{
		std::cout << "旧内容:" << std::endl;
		std::cout << ptr->filenumber[ret].p_content << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "新内容:";
		std::string namecon;
		std::string true_namecon;
		while (1)
		{
			if (!std::getline(std::cin, namecon))
			{
				std::cin.clear();
			}
			if (namecon == "OVER_ABOUT_STOP"||namecon=="\x1A")
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
		std::cout << "未找到" << std::endl;
	}
}

void delfile(buildinto *ptr)
{
	std::cout << "要删除的文件名:";
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
				  << "删除成功:)" << std::endl;
	}
	else
	{
		std::cout << "抱歉,未找到该文件" << std::endl;
	}
}

void searchf(buildinto *ptr)
{
	std::string name;
	std::cout << "文件名:";
	if (!std::getline(std::cin, name))
	{
		std::cin.clear();
	}
	int ret = orinit(ptr, name);
	if (ret != -1)
	{
		std::cout << "名称:" << ptr->filenumber[ret].p_name << std::endl;
		std::cout << "内容:" << std::endl;
		std::cout << ptr->filenumber[ret].p_content << std::endl;
		std::cout << "===============================================" << std::endl;
	}
	else
	{
		std::cout << "未找到" << std::endl;
	}
}

void delallfiles(buildinto *ptr)
{
	std::cout << "确定要删除所有虚拟文件吗?" << std::endl;
	std::cout << "1. 同意" << std::endl;
	std::cout << "2. 取消" << std::endl;
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
			std::cout << "删除成功" << std::endl;
			break;
		}
		if (chooses == "2")
		{
			break;
		}
		else
		{
			std::cout << "无效输入" << std::endl;
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

static void setting_make(yw_setting &fsy)
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
std::string prompt_str = "Core_Yuna$code->";
std::string virmpt_str = "Core_Yuna$code$Vircode->";
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
	std::cout << "==信息开始==" << std::endl;
	std::cout << "  名称:";
	show_osname();
	std::cout<<std::endl;
	std::cout << "  作者: Biriks-off" << std::endl;
	std::cout << "  环境: C++20, VS 2026, Microsoft Windows 10, MSVC" << std::endl;
	std::cout << "  版本: " << VER << std::endl;
	std::cout << "  语言: 简体中文" << std::endl;
	std::cout << "  创建日期(0.0.1): 2026.8.14" << std::endl;
	std::cout << "==信息结束==" << std::endl;
}

int main()
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
	while (1)
	{try{
		
		show_prompt();
		std::string code;
		if (!std::getline(std::cin, code))
		{
			std::cin.clear();
		}
		code.erase(0, code.find_first_not_of(" \t"));
		code.erase(code.find_last_not_of(" \t") + 1);
		if (code.empty())
			continue;
		if (code == "adder")
		{
			std::cout << "文件夹名称:";
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
		else if (code == "sp_help")
			sp_help();
		else if (code == "cls")
		{
			clear_OS();
		}
		else if (code == "quit")
		{
			break;
		}
		else if (code == "1" || code == "true")
			std::cout << "--真(1)\n";
		else if (code == "0" || code == "false")
			std::cout << "--假(0)\n";
		else if (code == "setting")
		{
			load_setting(fsy);
			setting_make(fsy);
			load_prompt_str(); 
           load_virmpt_str();
           load_osname_str();
		}
		else if (code == "del")
		{
			std::cout << "要删除的名称:";
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
					std::cout << "删除 "
							  << "\"" << name_rm << "\""
							  << "成功" << std::endl;
				}
				catch (std::filesystem::filesystem_error &a)
				{
					std::cout << "错误:" << a.what() << std::endl;
				}
			}
			else
			{
				show_osname();
				std::cerr << " 找不到 " << name_rm << std::endl;
			}
		}
		else if(code=="delall")
		{
			try
				{
					std::filesystem::remove("setting.txt");
std::filesystem::remove("mail.txt");
std::filesystem::remove("prompt.txt");
std::filesystem::remove("virmpt.txt");
std::filesystem::remove("start.txt");
std::filesystem::remove("osname.txt");		
					std::cout << "删除所有插件成功" << std::endl;
				}
				catch (std::filesystem::filesystem_error &a)
				{
					std::cout << "错误:" << a.what() << std::endl;
				}
		}
		else if (code == "mv")
{
    std::string source, dest_folder;
    std::cout << "源文件: ";
    std::getline(std::cin, source);
    source.erase(0, source.find_first_not_of(" \t\r\n"));
    source.erase(source.find_last_not_of(" \t\r\n") + 1);

    std::cout << "目标文件夹: ";
    std::getline(std::cin, dest_folder);
    dest_folder.erase(0, dest_folder.find_first_not_of(" \t\r\n"));
    dest_folder.erase(dest_folder.find_last_not_of(" \t\r\n") + 1);
    std::filesystem::path full_path = std::filesystem::path(dest_folder) / source;

    try
    {
        std::filesystem::rename(source, full_path);
        std::cout << "移动 " << source << " -> " << full_path.string() << " 成功" << std::endl;
    }
    catch (std::filesystem::filesystem_error &a)
    {
        show_osname();
        std::cout << "错误: " << a.what() << std::endl;
    }
}
		else if (code == "find")
		{
			std::string filename;
			std::cout << "文件名:" << std::endl;
			if (!std::getline(std::cin, filename))
			{
				std::cin.clear();
			}
			if (std::filesystem::exists(filename))
			{
				try
				{
					show_osname();
					std::cout << " 找到"
							  << "\"" << filename << "\""
							  << "成功" << std::endl;
				}
				catch (std::filesystem::filesystem_error &a)
				{
					show_osname();
					std::cout << "错误:" << a.what() << std::endl;
				}
			}
			else
			{
				show_osname();
				std::cout << " 找不到"
						  << "\"" << filename << "\"" << std::endl;
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
			std::cerr << "按 Ctrl z/d+回车 退出 cpp" << std::endl;
			std::cout << "C++ 文件名:";
			std::string cppname;
			if (!std::getline(std::cin, cppname))
			{
				std::cin.clear();
			}
			std::cout << "C++ 版本(数字):";
			std::string cppver;
			if (!std::getline(std::cin, cppver))
			{
				std::cin.clear();
			}
			std::cout << "运行文件名(不带后缀):";
			std::string batname;
			if (!std::getline(std::cin, batname))
			{
				std::cin.clear();
			}
			while (1)
			{
				std::cout << "系统:" << std::endl;
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
		
				else if (code == "cbat")
		{
			std::cerr << "按 Ctrl z/d+回车 退出 cbat" << std::endl;
			std::cout << "C 文件名(不带后缀):";
			std::string cname;
			if (!std::getline(std::cin, cname))
			{
				std::cin.clear();
			}
			std::cout << "C 版本(数字):";
			std::string cver;
			if (!std::getline(std::cin, cver))
			{
				std::cin.clear();
			}
			std::cout << "运行文件名(不带后缀):";
			std::string cbatname;
			if (!std::getline(std::cin, cbatname))
			{
				std::cin.clear();
			}
			while (1)
			{
				std::cout << "系统:" << std::endl;
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
		else if (code == "js")
{
    std::cerr << "按 Ctrl z/d+回车 退出 js" << std::endl;
    std::cout << "JS 文件名(不带后缀):";
    std::string jsname;
    if (!std::getline(std::cin, jsname))
    {
        std::cin.clear();
    }

    while (1)
    {
        std::cout << "系统:" << std::endl;
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
else if (code == "py")
{
    std::cerr << "按 Ctrl z/d+回车 退出 py" << std::endl;
    std::cout << "Python 文件名(不带后缀):";
    std::string pyname;
    if (!std::getline(std::cin, pyname))
    {
        std::cin.clear();
    }
    std::cout << "Python 版本(数字):";
    std::string pyver;
    if (!std::getline(std::cin, pyver))
    {
        std::cin.clear();
    }

    while (1)
    {
        std::cout << "系统:" << std::endl;
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
                filepy << "python" + pyver + " " + pyname + ".py" << std::endl;
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
		else if (code == "hello" || code == "hi" || code == "hey")
		{
			std::cout << "你好,欢迎来到 ";
			show_osname();
			std::cout<<std::endl;
		}
		else if (code == "virfl")
		{
			while (true)
			{
		        show_virmpt();
				std::string codevir;
				if (!std::getline(std::cin, codevir))
				{
					std::cin.clear();
					break;
				}
				codevir.erase(0, codevir.find_first_not_of(" \t"));
				codevir.erase(codevir.find_last_not_of(" \t") + 1);
				if (codevir.empty())
					continue;
				if (codevir == "back")
				{
					std::cout << "返回 CODE 层" << std::endl;
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
				else
				{
					show_osname();
					std::cerr << " 无法处理"
							  << "\"" << codevir << "\"" << std::endl;
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
			std::cout << "文件名:";
			std::string name2;
			if (!std::getline(std::cin, name2))
			{
				std::cin.clear();
			}
			std::cout << "文件扩展名:" << std::endl;
			std::cerr << "提示: 不需要输入 \".\" " << std::endl;
			std::string name3;
			if (!std::getline(std::cin, name3))
			{
				std::cin.clear();
			}
			std::cout << "文件内容:" << std::endl;
			std::cout << "(按 Ctrl z/d+回车 结束文件编辑)" << std::endl;
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
		else if (code == "chcon")
		{
					std::string name_chcon;
					std::string name_chcon_content;
					std::string name_chcon_true;
					std::cout << "文件名:";
					if (!std::getline(std::cin, name_chcon))
					{
						std::cin.clear();
					}
					if (std::filesystem::exists(name_chcon))
					{
						try
						{
							std::cout << "新内容:" << std::endl;
							std::cout << "(按 Ctrl z/d+回车 结束文件编辑)" << std::endl;
							while (std::getline(std::cin, name_chcon_content))
							
							{
								 if (name_chcon_content == "OVER_ABOUT_STOP") { break; }
								name_chcon_true += name_chcon_content + "\n";
							}
							std::cin.clear();
							std::ofstream filech(name_chcon);
							filech << name_chcon_true;
							filech.close();
							std::cout << "修改 "
									  << "\"" << name_chcon << "\" "
									  << "的内容成功" << std::endl;
						
						}
						catch (std::filesystem::filesystem_error &o)
						{
							show_osname();
							std::cerr << "错误:" << o.what() << std::endl;
							break;
						}
					}
					else
					{
						show_osname();
						std::cerr << " 找不到"
								  << "\"" << name_chcon << "\"" << std::endl;
						
					}
		}
	 else if (code == "list")
		{
			try
			{
				for (const auto &entry : std::filesystem::directory_iterator("."))
				{
					std::cout << entry.path().filename().string() << std::endl;
				}
			}
			catch (std::filesystem::filesystem_error &listfile)
			{
				show_osname();
				std::cout << "错误:" << listfile.what() << std::endl;
			}
		}
		else if (code == "look")
		{
#if defined(_WIN32)
			system("start cmd");
#elif defined(__APPLE__)
			system("open -a Terminal .");
#elif defined(__linux__)
			system("x-terminal-emulator &");
#endif
		}
		else if (code == "opexe")
		{
			std::cout << "文件名:";
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
		else
		{
			show_osname();
			std::cerr << " 无法处理"
					  << "\"" << code << "\"" << std::endl;
		}
	}
	catch(const std::system_error&a)
	{
	    show_osname();
	    std::cerr<<"系统错误:"<<a.what()<<std::endl;
       std::cin.clear();
	}
}	
}