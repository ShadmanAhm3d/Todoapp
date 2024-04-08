#include <fstream>
#include <iostream>
#include <string>

using namespace std;
// TODO : if that file does not exist create it ,but it exist
// just do the operations

// TODO : after TODO 1 is done , now i want to read from that file and display
// in console

// TODO : functionify everything

// TODO : Show task numbers in each tassk ;
// TODO : ADD a task delete functionality


//TODO : Make it production ready
// DONE : TODO1 and TODO2 and TODO3 and todo4 and todo5
/*
int readline(const string &filename) {
  fstream file(filename);

  int count = 0;
  string line;
  while (getline(file, line)) {
    count++;
  }

  return count+1;
} */



void showTasks() {

  // har line ke pehle ek number show karo (recal everytime)

  // int linenumber = readline("Myset.dat");
  
  fstream file;
  file.open("Myset.dat", ios::in);
  int i = 0;
  if (file.is_open()) {
    string buffer;
    while (getline(file, buffer)) {
      i++;
      cout << i << " ." << buffer << endl;
    }
  }
}

void addit(string toBeWritten, string err) {

  fstream file;

  // count number of lines in the file
  // add a preset befroe toBeWritten

  file.open("Myset.dat", ios::app);
  if (file.is_open()) {
    // file << "[ " <<linenumber <<"]"<<toBeWritten << endl;
    file << toBeWritten << endl;
    cout<<"Task has been added successfully" <<endl;
  } else {
    throw err;
  }

  file.close();
}

void deleteit(int lineNumber) {
  fstream file;
  fstream tempFile;
  file.open("Myset.dat",ios::in);
  tempFile.open("temp.dat",ios::out);

  if (!file || !tempFile) {
    cerr << "Error: Unable to open file for deletion." << endl;
    return;
  }

  int count = 0;
  string line;
  while (getline(file, line)) {
    count++;
    if (count != lineNumber) {
      tempFile << line << endl;
    }
  }

  file.close();
  tempFile.close();

  // Remove the original file
  remove("Myset.dat");

  // Rename the temporary file to the original filename
  rename("temp.dat", "Myset.dat");

  cout << "Task " << lineNumber << " deleted successfully." << endl;
}
int main(int argc, char *argv[]) {
  string err = "some kind of error has come";
  cout << endl << endl;

  if (argc < 2) {
    cout << "Usage: " << argv[0] << " [add/showtasks] [task]" << endl;
    return 1;
  }

  fstream file;
  string s = argv[1];
  if (s == "add") {
    if (argc < 3) {
      cout << "Usage: " << argv[0] << " add [task]" << endl;
      return 1;
    }
    string writeInTask = argv[2];
    addit(writeInTask, err);
  } else if (s == "showtasks") {
    showTasks();
  } else if (s == "del") {
    int n;
    cout << "Which task ?";
    cin >> n;
    deleteit(n);
  }
  /*
  file.open("Myset.dat",ios::in);
  if(file.is_open()){
    string buffer ;
    while(getline(file,buffer)){
      cout << buffer << endl;
    }
  }
  */

  file.close();
}
