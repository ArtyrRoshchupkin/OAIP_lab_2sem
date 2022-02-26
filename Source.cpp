#include<iostream>
#include<string.h>
#include<io.h>
#include<iomanip>
#include<Windows.h>
#include<stdio.h>

using namespace std;
struct STUDENTS 
{

    char lastname;
    float sr;
    int i, m, f, n;

};

void Create(FILE* file, char name[255]);

void Read(FILE* file, char name[255]);

void Add(FILE* file, char name[255]);

void Task(FILE* file, char name[255]);



STUDENTS In();

int main() 
{
    
}

void Create(FILE* file, char name[255])
{
    int n;
    cout << "enter number of student\n";
    cin >> n;
    STUDENTS h;

    fopen_s(&file, name, "wb"); //октрыли файл для записи

    for (int i = 0; i < n; i++)
    {
        h = In();
        fwrite(&h, sizeof(STUDENTS), 1, file);
    }
    fclose(file);
}

void Read(FILE* file, char name[255])
{
    STUDENTS h;
    fopen_s(&file, name, "rb");

    if (file!=NULL)
    {
        cout << " Group Surname Phisics Math Informatics GPA\n";
    
        while (fread(&h, sizeof(STUDENTS), 1, file))
        {
            cout << " "<< h.n <<" " << h.lastname << " " << h.f << " " << h.m << " " << h.i << " "  << h.sr << endl;
            cout << endl;
        }
    }

    fclose(file);
}

void Add(FILE* file, char name[255])
{
    STUDENTS h;
    fopen_s(&file, name, "ab");
    int k;
    cout << "enter number of student\n";
    cin >> k;

    fseek(file, 0, SEEK_END); //переходим в конец файла, 0 означает что к концу ничего не прибавляем

    for (int i = 0; i < k; i++)
    {
        h = In();
        fwrite(&h, sizeof(STUDENTS), 1, file);        
    }
    fclose(file);
}

void Task(FILE* file, char name[255])
{
    STUDENTS h;
    fopen_s(&file, name, "");
    fclose(file);
}

STUDENTS In()
{
    STUDENTS g;
    cout << "enetr surname\n";
    cin >> g.lastname;
    cout << "enetr number of group\n";
    cin >> g.n;
    cout << "enetr math mark\n";
    cin >> g.m;
    cout << "enetr fiziks mark\n";
    cin >> g.f;
    cout << "enetr informatic mark\n";
    cin >> g.i;
    g.sr = (g.m+g.f+g.i) / 3.;
    return g;
}
