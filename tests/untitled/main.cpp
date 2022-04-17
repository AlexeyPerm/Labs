#include<vector>
#include<iostream>
#include<string>
#include <ctime>

using namespace std;

struct date {
    int day;
    int month;
    int year;

    date() {
        day = 0;
        month = 0;
        year = 0;
    }
    date(const date& other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay(int day) {
        this->day = day;
    }
    int getDay() {
        return day;
    }

    void setMonth(int month) {
        this->month = month;
    }
    int getMonth() {
        return month;
    }


    void setYear(int year) {
        this->year = year;
    }
    int getYear() {
        return year;
    }
};


class PERSON {

protected:
    string name;
    string surname;
    string middle_n;
    string gender;
    date birthday;
public:
    friend istream& operator>>(istream&, PERSON&);
    friend ostream& operator<<(ostream&, PERSON&);
    PERSON() {
        name = "NULL";
        surname = "NULL";
        middle_n = "NULL";
        gender = "NULL";
        birthday.day = 0;
        birthday.month = 0;
        birthday.year = 0;
    }

    //операция разрешения области действия ::

    PERSON(string name, string surname, string middle_n, string gender, date birthday) {
        this->name = name;
        this->surname = surname;
        this->middle_n = middle_n;
        this->gender = gender;
        this->birthday = birthday;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setSurname(string surname) {
        this->surname = surname;
    }
    string getSurname() {
        return surname;
    }
    void setMiddle_n(string middle_n) {
        this->middle_n = middle_n;
    }
    string getMiddle_n() {
        return middle_n;
    }

    void setGender(string gender) {
        this->gender = gender;
    }
    string getGender() {
        return gender;
    }
    void setDay(int day) {
        this->birthday.day = day;
    }
    int getDay() {
        return birthday.day;
    }

    void setMonth(int month) {
        this->birthday.month = month;
    }
    int getMonth() {
        return birthday.month;
    }


    void setYear(int year) {
        this->birthday.year = year;
    }
    int getYear() {
        return birthday.year;
    }


    // Getter
    void printperson() {
        cout << name << surname << middle_n << gender << birthday.day << birthday.month << birthday.year;
    }
};

istream& operator>>(istream& is, PERSON& first) {
    is >> first.name >> first.surname >> first.middle_n >> first.gender >> first.birthday.day;
    return is;
}
ostream& operator<<(ostream& os, PERSON& first) {
    os << first.name << first.surname << first.middle_n << first.gender << first.birthday.day;
    return os;
}


class WORKER : public PERSON {
protected:

    PERSON person1;
    int hours;
    string expirience;
    int payroll;
    int payforhour;


public:
    int ID;
    friend bool operator>(const WORKER& first, int value);
    friend istream& operator>>(istream&, WORKER&);
    friend ostream& operator<<(ostream&, WORKER&);

    WORKER() : PERSON() {

        hours = 0;
        expirience = "0";
        payroll = 0;
        payforhour = 0;
        ID = 0;

    }
    WORKER(PERSON person1, int hours, string expirience, int payroll, int payforhour, int ID) : PERSON(person1) {

        this->hours = hours;
        this->expirience = std::move(expirience);
        this->payroll = payroll;
        this->payforhour = payforhour;
        this->ID = ID;
    }
    WORKER(string name, string surname, string middle_n, string gender, const date& birthday, int hours, string expirience,
           int payroll, int payforhour, int ID) : PERSON(name, std::move(surname), std::move(middle_n), gender, birthday) {

        this->hours = hours;
        this->expirience = expirience;
        this->payroll = payroll;
        this->payforhour = payforhour;
        this->ID = ID;
        void enterdata() {
            string name1;
            string surname1;
            string middle_n1;
            string gender1;
            int day1 = 0;
            int month1 = 0;
            int year1 = 0;
            int hours;
            string expirience;
            int payroll = 0;
            int payforhour = 0;
            int ID = 0;

            cout << "enter name: ";
            cin >> name1;
            cout << "enter surname: ";
            cin >> surname1;
            cout << "enter middle name: ";
            cin >> middle_n1;
            cout << "enter gender: ";
            cin >> gender1;
            cout << "enter day of birth: ";
            cin >> day1;
            cout << "enter month of birth : ";
            cin >> month1;
            cout << "enter year of birth : ";
            cin >> year1;
            cout << "enter hours: ";
            cin >> hours;
            cout << "enter expirience: ";
            cin >> expirience;
            cout << "enter payroll: ";
            cin >> payroll;
            cout << "enter payforhour: ";
            cin >> payforhour;
            cout << "enter ID: ";
            cin >> ID;


            date date1(day1, month1, year1);
            PERSON person(name1, surname1, middle_n1, gender1, date1);
            WORKER worker(person, hours, expirience, payroll, payforhour, ID);

            vec.push_back(worker);
            cout << endl << "data added" << endl;
        }
        void printdata() {
            for (int i = 0; i < vec.size(); i++) {
                cout << vec[i] << endl;
            }
        }
        void checkindex() {
            int index = 0;
            cout << "Vvedite index:";
            cin >> index;
            cout << vec.at(index) << endl;
        }

        void dellastdata() {
            vec.pop_back();
            cout << "last element removed" << endl;
        }
        void changeindexelement() {
            vector<worker>::iterator it = vec.begin();
            int index = 0;
            cout << "Vvedite index:";
            cin >> index;
            advance(it, index);
            string name1;
            string surname1;
            string middle_n1;
            string gender1;
            int day1 = 0;
            int month1 = 0;
            int year1 = 0;
            int hours;
            string expirience;
            int payroll = 0;
            int payforhour = 0;
            int ID = 0;

            cout << "enter name: ";
            cin >> name1;

            cout << "enter surname: ";
            cin >> surname1;
            cout << "enter middle name: ";
            cin >> middle_n1;
            cout << "enter gender: ";
            cin >> gender1;
            cout << "enter day of birth: ";
            cin >> day1;
            cout << "enter month of birth : ";
            cin >> month1;
            cout << "enter year of birth : ";
            cin >> year1;
            cout << "enter hours: ";
            cin >> hours;
            cout << "enter expirience: ";
            cin >> expirience;
            cout << "enter payroll: ";
            cin >> payroll;
            cout << "enter payforhour: ";
            cin >> payforhour;
            cout << "enter ID: ";
            cin >> ID;


            date date1(day1, month1, year1);
            PERSON person(name1, surname1, middle_n1, gender1, date1);

            WORKER worker(person, hours, expirience, payroll, payforhour, ID);

            vec.push_back(worker);
            cout << endl << "data added" << endl;
            vec.insert(it, worker);
            cout << "data added" << endl;

        }
        void deleteindexelement() {
            vector<WORKER>::iterator it = vec.begin();
            int index = 0;
            cout << "Vvedite index:";
            cin >> index;
            advance(it, index);
            vec.erase(it);
            cout << " element with index" << index << " removed" << endl;
        }

        void cleardata() {
            vec.clear();
            cout << "vector size now:" << vec.size();
        }
        void salary() {
            int size = 0;
            int id = 0;
            cout << "id";
            cin >> id;
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i].ID == id) {
                    cout << "size: ";
                    cin >> size;
                    for (int i = 0; i < size; i++) {
                        int salary1 = 0;
                        string count_salary1;
                        cout << "salary: ";
                        cin >> salary1;
                        cout << "count_salary: ";
                        cin >> count_salary1;

                        count_salary a(salary1, id, count_salary1);
                        salary.push_salary(a);
                    }
                }
            }

        }
        void checksalary() {
            int id = 0;
            cout << "id";
            cin >> id;
            cout << "salary worker with id" << id << endl;
            cout << "salary:\t" << "count_salary:\t" << endl;
            for (int i = 0; i < salary.size(); i++) {
                if (salary[i].id == id) {
                    cout << salary[i].id << "\t" << salary[i].count_salary << "\t" << endl;
                }
            }
        }

        istream& operator>>(istream& is, WORKER& first) {
            is >> (PERSON&) first;
            is >> first.hours >> first.expirience >> first.payroll >> first.payforhour >> first.ID;
            return is;
        }

        ostream& operator<<(ostream& out, WORKER& first) {
            out << (PERSON&) first;
            out << first.hours << first.expirience << first.payroll << first.payforhour << first.ID;
            return out;
        }


    }

    void sethours(int hours) {
        this->hours = hours;
    }
    int gethours() {
        return hours;
    }
    void setexpirience(int expirience) {
        this->expirience = expirience;
    }
    string getexpirience() {
        return expirience;
    }
    void setpayroll(int payroll) {
        this->payroll = payroll;
    }
    int getpayroll() {
        return payroll;
    }

    void setpayforhour(int payforhour) {
        this->payforhour = payforhour;
    }
    int getpayforhour() {
        return payforhour;
    }

    void setID(int ID) {
        this->ID = ID;
    }
    int getID() {
        return ID;
    }
    void printf() {

        cout << name << surname << middle_n << birthday.day << expirience << payroll << payforhour;
    }
};




int main() {
    WORKER a;
    /*salary ;*/
    int key = 0;
    do {
        cout << "menu:" << endl;
        cout << "to enter data enter 1" << endl;
        cout << "to look all data enter 2" << endl;
        cout << "to look data by index enter 3" << endl;
        cout << "to enter salary enter 4" << endl;
        cout << "to delete last data enter 5" << endl;
        cout << "to change data with index enter 6" << endl;
        cout << "to delete data with index enter 7" << endl;
        cout << "to clear data enter 8" << endl;
        cout << "to complete work enter 0" << endl;
        cin >> key;
        switch (key) {
            case 1:
                a.enterdata();
                break;
            case 2:
                a.printdata();
                break;
            case 3:
                a.checkindex();
                break;
            case 4:
                a.salary1();
                break;
            case 5:
                a.dellastdata();
                break;
            case 6:
                a.changeindexelement();
                break;
            case 7:
                a.deleteindexelement();
                break;
            case 8:
                a.cleardata();
                break;
            case 9:
                a.checksalary();
                break;
        }
    } while (key);

}