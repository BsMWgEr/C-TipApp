#include <iostream>

using namespace std;

void tipSetter(const string& a, double b);

int main() {
    string tip_percent;
    string person_name;
    string answer;
    string manager_answer;
    double amount_total;

    cout << "Hello, my name is Fred and my reason for existence is to tell you how much to tip your server.\n"
            "Please enter your first name to continue:\n...";
    cin >> person_name;
    person_name[0] = char(toupper(person_name[0]));
    cout << "Hello " << person_name << ".\nWhat is your total??\n...$";
    cin >> amount_total;
    cout << "How was your service?\n"
            "Hint: Try either bad, ok, good, or great\n...";
    cin >> tip_percent;

    for (int i = 0; i < person_name.size(); i++){
        tip_percent[i] = char(tolower(tip_percent[i]));
    }

    if(tip_percent == "ok" || tip_percent == "good" || tip_percent == "great"){
        tipSetter(tip_percent, amount_total);
        cout << "Thanks for using me! Have a great day " << person_name << "!!" << endl;
        return 0;
    }else if ("bad" == tip_percent) {
        cout << "I am set to give 15% for bad service\n"
                "Is this acceptable or would you like to set your own?" << endl;
        cin >> answer;
        if ("yes" == answer) {
            tipSetter(person_name, amount_total);
            return 0;
        } else if ("no" == answer) {
            double custom_tip_percentage;
            cout << "What percentage would you like to tip?\n"
                    "...";
            cin >> custom_tip_percentage;
            double q = 100;
            double custom_tip;
            custom_tip = (custom_tip_percentage / 100) * amount_total;
            double custom_tip_total = custom_tip + amount_total;
            cout << "Tip amount: $ " << custom_tip << endl;
            cout << "Total amount: $ " << custom_tip_total << endl;
            cout << "Would you like to speak to the manager? " << endl;
            cin >> manager_answer;
            if ("yes" == manager_answer) {
                cout << "I am the manager " + person_name + "! A 30% service charge has now been added to your total!"
                     << endl;
                double service_charge = (amount_total * 0.3) + amount_total;
                cout << "Amount Due: $ " << service_charge << endl;
                cout << "Have a great day  " << person_name << "!!" << endl;
                return 0;
            } else if ("no" == manager_answer) {
                tipSetter(tip_percent, amount_total);
                return 0;
            }
        }
    } else {
        cout << "Wrong entry " + person_name + ". Try again using the following words: bad, ok, good, great.\n"
                                                           "Thanks " + person_name + "!" << endl;
        return 0;
    }
}


void tipSetter(const string& a, double b) {
    double good_t = .20;
    double ok_t = .18;
    double great_t = .25;
    double tip_p;
    string string_1 = "Tip Total: $";
    string string_2 = "Total $";

    if (a == "ok") {
        tip_p = ok_t;
    } else if (a == "good") {
        tip_p = good_t;
    }else {
        tip_p = great_t;
    }

    double i = b * tip_p;
    double j = b + i;
    cout << "Tip Percent: " << tip_p * 100 << "%" << endl;
    cout << string_1 << i << endl;
    cout << string_2 << j << endl;
}
