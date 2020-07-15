/*
 * @lc app=leetcode id=1169 lang=cpp
 *
 * [1169] Invalid Transactions
 */

// @lc code=start
class Solution {
struct Transaction {
    Transaction() : time(0), amount(0), name(""), city(""), id(-1) {}
    Transaction(const string& record, int i) : id(i) {
        size_t idx(record.find(',')), pre(0);
        name.assign(record.substr(0, idx));
        pre = idx + 1;
        idx = record.find(',', pre);
        time = stoi(record.substr(pre, idx - pre));
        pre = idx + 1;
        idx = record.find(',', pre);
        amount = stoi(record.substr(pre, idx - pre));
        pre = idx + 1;
        city.assign(record.substr(pre));
    }
    void print() const {
        cout << id << ':' << name << ',' << time << ',';
        cout << amount << ',' << city << endl;
    }
    bool operator<(const Transaction& other) const {
        if (name == other.name) {
            return time < other.time;
        }
        return name < other.name;
    }
    int id;
    int time;
    int amount;
    string name;
    string city;
};
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> transVec;
        int i(0);
        for (string& record : transactions) {
            transVec.push_back(Transaction(record, i++));
            //transVec.back().print();
        }
        //sort(transVec.begin(), transVec.end());
        //for (auto& t : transVec) { t.print(); }
        
        unordered_set<int> ust;
        for (int i(0); i < transVec.size(); ++i) {
            if (transVec[i].amount > 1000) { ust.insert(transVec[i].id); }
            for (int j(i + 1); j < transVec.size(); ++j) {
                if (transVec[i].name == transVec[j].name && transVec[i].city != transVec[j].city && \
                    abs(transVec[i].time - transVec[j].time) <= 60) {
                    ust.insert(transVec[i].id);
                    ust.insert(transVec[j].id);
                }
            } 
        }

        vector<string> ans;
        /*
        int tim(0);
        for (i = 0; i < transVec.size(); ++i) {
            if (transVec[i].amount > 1000) { ust.insert(transVec[i].id); }
            if (i == 0 || transVec[i].name != transVec[i - 1].name) { tim = transVec[i].time; }
            else if (transVec[i].name == transVec[i - 1].name && transVec[i].city != transVec[i - 1].city) { tim = transVec[i - 1].time; }
            if (i > 0 && transVec[i].name == transVec[i - 1].name && \
                transVec[i].city != transVec[i - 1].city && transVec[i].time - tim <= 60) {
                ust.insert(transVec[i].id);
                ust.insert(transVec[i - 1].id);
            }
        }
        */

        for (int id : ust) { ans.push_back(transactions[id]); }

        return ans;
    }
};
// @lc code=end

