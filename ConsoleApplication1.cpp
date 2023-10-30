
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User {
public:
    string id;
    string name;
    string phone;
    string salary;
    string profession;
    User() {}
    User(string id, string name, string phone, string salary, string profession) {
        this->id = id;
        this->name = name;
        this->phone = phone;
        this->salary = salary;
        this->profession = profession;
    }
    void print(ofstream& out) {
        out << this->id << "," << this->name << "," << this->phone << "," << this->salary << "," << this->profession << endl;
    }
    void print() {
        cout << this->id << ", " << this->name << ", " << this->phone << ", " << this->salary << ", " << this->profession << endl;
    }
};

class UsersDB {
public:
    UsersDB(string path) {
        this->path = path;
        initDB();
    }
    void add(User user) {
        DB.push_back(user);
        dumbDB();
    }
    void print() {
        for (auto user : DB) {
            user.print();
        }
    }
    void Delete(string id) {
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].id == id) {
                DB.erase(DB.begin() + i);
                break;
            }
        }
        dumbDB();
    }
    void search_id() {
        string s_id;
        cin >> s_id;
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].id == s_id) {
                DB[i].print();
                break;
            }
        }
    }
    void search_name() {
        string s_name;
        cin >> s_name;
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].name == s_name) {
                DB[i].print();
                break;
            }
        }
    }
    void search_phone() {
        string s_phone;
        cin >> s_phone;
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].phone == s_phone) {
                DB[i].print();
                break;
            }
        }
    }
    void search_salary() {
        string s_salary;
        cin >> s_salary;
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].salary == s_salary) {
                DB[i].print();
                break;
            }
        }
    }
    void search_profession() {
        string s_profession;
        cin >> s_profession;
        for (int i = 0; i < DB.size(); i++) {
            if (DB[i].profession == s_profession) {
                DB[i].print();
                break;
            }
        }
    }
private:
    void initDB() {
        ifstream in;
        in.open(path);
        if (in.is_open())
        {
            string line;
            while (getline(in, line))
            {
                string id;
                int guga = 1;
                char h = ',';
                string name;
                string phone;
                string salary;
                string profession;
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == h) {
                        guga += 1;
                        continue;
                    }
                    if (guga == 1) {
                        id = id + line[i];
                    }
                    if (guga == 2) {
                        name = name + line[i];
                    }
                    if (guga == 3) {
                        phone = phone + line[i];
                    }
                    if (guga == 4) {
                        salary = salary + line[i];
                    }
                    if (guga == 5) {
                        profession = profession + line[i];
                    }
                }
                //if (sscanf_s(line.c_str(), "%d, %s, %s, %s, %s", &id, name, 256, phone, 256, salary, 256, profession, 256) == 5) {
                User user(id, name, phone, salary, profession);
                DB.push_back(user);
            }
        }
        in.close();
    }
    void dumbDB() {
        ofstream out;
        out.open(path);
        if (out.is_open()) {
            for (auto user : DB) {
                user.print(out);
            }
        }
        out.close();
    }
    vector<User> DB;
    string path;
};
void AddUser(UsersDB& db) {
    cout << "add id:" << endl;
    string id;
    cin >> id;
    cout << "add name:" << endl;
    string name;
    cin >> name;
    cout << "add phone:" << endl;
    string phone;
    cin >> phone;
    cout << "add salary:" << endl;
    string salary;
    cin >> salary;
    cout << "add profession:" << endl;
    string profession;
    cin >> profession;
    User uswe(id, name, phone, salary, profession);
    db.add(uswe);
}

int main()
{
    string path = "MyFile.txt";
    UsersDB db(path);
    bool i = true;
    while (i)
    {
        cout << "1. add" << endl;
        cout << "2. print" << endl;
        cout << "3. search" << endl;
        cout << "4. delete" << endl;
        cout << "5. exit" << endl;
        int screen;
        cin >> screen;
        switch (screen)
        {
            case 1:
                AddUser(db);
                break;
            case 2:
                db.print();
                break;
            case 3:
                cout << "1. search for id" << endl;
                cout << "2. search for name" << endl;
                cout << "3. search for phone" << endl;
                cout << "4. searsh for salary" << endl;
                cout << "5. search for profession" << endl;
                int three;
                cin >> three;
                switch (three)
                {
                    case 1:
                        cout << "insert id" << endl;
                        db.search_id();
                        break;
                    case 2:
                        cout << "insert name" << endl;
                        db.search_name();
                        break;
                    case 3:
                        cout << "insert phone" << endl;
                        db.search_phone();
                        break;
                    case 4:
                        cout << "insert salary" << endl;
                        db.search_salary();
                        break;
                    case 5:
                        cout << "insert profession" << endl;
                        db.search_profession();
                        break;
                }
                break;
            case 4: {
                cout << "cout id" << endl;
                string idUser;
                cin >> idUser;
                db.Delete(idUser);
                break;}
            case 5:
                i = 0;
                break;
        }
    }

}