#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <fstream>
#include <cstdio>
#include <string>
#include <string>
#include <vector>
#include <sstream>
#include <SFML/Network.hpp>
int main();
void rerun(std::string tool);
std::string getFileContents(std::ifstream& File);
void banner_print(std::string file);

bool port_is_open(const std::string& address, int port) {
	sf::Time Timeout = sf::milliseconds(20);
	return (sf::TcpSocket().connect(address, port, Timeout) == sf::Socket::Done);
}

class port_scanner {
public:
	
	void scanner_conf() {
		system("cls");
		banner_print("port_scanner.txt");
		std::string port_range;
		int port_1 = NULL;
		std::string delim = "-";
		int port_2 = NULL;
		std::vector<int> ports;
		std::string address;
		std::cout << "Enter an IP Address to scan :: ";
		std::getline(std::cin, address);
		std::cout << "Enter a port range for example 0-1023 or 25,53,80 :: ";
		std::getline(std::cin, port_range);
		
		size_t pos = 0;
		if ((pos = port_range.find(delim)) != std::string::npos){
			std::string token;
			while ((pos = port_range.find(delim)) != std::string::npos) {
				token = port_range.substr(0, pos);
				port_range.erase(0, pos + delim.length());
			}
			port_1 = stoi(token);
			port_2 = stoi(port_range);
			
			if (port_1 > port_2) {
				std::swap(port_1, port_2);
			}
			while (port_2 >= port_1) {
				bool open = port_is_open(address, port_1);
				if (open) printf("%d :: OPEN\n\n", port_1);
				port_1++;
			}
			rerun("PortScan");
		}
		else
		{
			std::string delim_c = ",";
			std::string token;
			while ((pos = port_range.find(delim_c)) != std::string::npos) {
				token = port_range.substr(0, pos);
				ports.push_back(stoi(token));
				port_range.erase(0, pos + delim_c.length());
				
			}
			ports.push_back(stoi(port_range));
			
			for (int i = 0; i < ports.size(); i++) {
				
			}
			rerun("PortScan");
			//
		}
	}
};

class registry_scanner {
	public:

	private:

};

class dir_scanner {
	public:

	private:
};

class file_searcher {
	public:

	private:

};

class anti_virus {
	public:

	private:

};

std::string getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

void banner_print(std::string file) {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);
	std::ifstream Reader(file);             //Open file
	std::string Art = getFileContents(Reader);       //Get file
	std::cout << Art << std::endl;               //Print it to the screen
	Reader.close();
}

/*
string tool reruns for ref

PortScan
RegScan
DirScan
FileSearch
AVScan

*/
void rerun(std::string tool) {
	printf("Scan is Complete, would you like to:\nA:) Use Another Tool\nB:) Do More With the Current Tool\nC:) Exit completely\nThe Choice is yours:");
	std::cin.clear();
	bool done = false;
	char i = NULL;
	std::cin >> i;
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
	i = toupper(i);
	if (i == 'A') {
		main();
	}
	else if (i == 'B') {
		if (tool == "PortScan") {
			port_scanner p_s;
			std::cin.clear();
			p_s.scanner_conf();
		}
		else if (tool == "RegScan") {
			registry_scanner r_s;
			/*
			ADD TO AFTER SCANNER DEVELOPED
			*/
		}
		else if (tool == "DirScan") {

			/*
			ADD TO AFTER SCANNER DEVELOPED
			*/
		}
		else if ("FileSearch") {
			file_searcher f_s;
			/*
				ADD TO AFTER SCANNER DEVELOPED
			*/
		}
		else if ("AVScan") {
			anti_virus a_v;
			/*
			ADD TO AFTER SCANNER DEVELOPED
			*/
		}
		else {
			std::cout << "CONGRADU-MCFUCKIN-LATIONS SOMEHOW YOUR DUMBASS BROKE THE PROGRAM>>>> RETURNING TO MAIN" << std::endl;
			main();
		}

	}
	else if (i == 'C') {
		exit(0);
	}
	else {
		std::cout << "Invalid Option" << std::endl;
		rerun("Rerun");
	}
}



int main(void) {
	system("cls");
	//Print ACID ToolKit Banner
	banner_print("banner.txt");
	// Setup objects
	port_scanner port_scan;
	registry_scanner registry_scan;
	dir_scanner dir_scan;
	file_searcher file_search;
	
	// Prompt User for tool they would like to use
	char a;
	std::string p_s = "Port Scanner";
	std::string r_s = "Registry Scanner";
	std::string d_s = "Directory Scanner";
	std::string f_s = "File Search";
	printf("Pick Your Poison:\nA:)%s\nB:)%s\nC:)%s\nD:)%s\n", p_s.c_str(), r_s.c_str(), d_s.c_str(), f_s.c_str());
	std::cin >> a;
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
	a = toupper(a);

	switch (a)
	{
		case 'A':
			// Clear Option Screen and execute users selection
			system("cls");
			std::cin.clear();
			banner_print("port_scanner.txt");
			port_scan.scanner_conf();
			break;
		
		case 'B':
			system("cls");
			std::cin.clear();
			printf("Your option was: %c", a);
			break;

		case 'C':
			system("cls");
			std::cin.clear();
			printf("Your option was: %c", a);
			break;
		
		case 'D':
			std::cin.clear();
			system("cls");
			banner_print("file_scan_banner.txt");
			break;
		default:
			std::cout << "Invalid Input, Please try again." << std::endl;
			break;
	}

}