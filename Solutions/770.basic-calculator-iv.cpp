/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 */

// @lc code=start
class Solution {
class Util {
public:
    static int findRightParaIndex(const string& str, const int beg, const int end) {
        if (beg >= end || str[beg] != '(') { return -1; }
        int cnt(1);
        for (int i(beg + 1); i <= end; ++i) {
            if (str[i] == '(') { ++cnt; }
            else if (str[i] == ')') { --cnt; }
            if (cnt == 0) { return i; }
        }
        return -1;
    }
};
struct FreeVarible {
    FreeVarible() : coef_(0), isOrdered_(false) {}
    FreeVarible(const int coef) : coef_(coef) {}
    FreeVarible(const vector<string>& varList, const int coef = 1) : coef_(coef), varList_(varList) {}
    FreeVarible(const FreeVarible& fv) : coef_(fv.coef_), isOrdered_(fv.isOrdered_), varList_(fv.varList_) {}
    FreeVarible& operator=(const FreeVarible& fv) {
        if (this != &fv) {
            coef_ = fv.coef_;
            isOrdered_ = fv.isOrdered_;
            varList_ = fv.varList_;
        }
        return *this;
    }
    ~FreeVarible() { varList_.clear(); }
    inline bool isValid() { return coef_ != 0; }
    void adjustVarOrder() {
        if (!isValid()) { return; }
        if (!isOrdered_) { sort(varList_.begin(), varList_.end()); }
        isOrdered_ = true;
    }
    bool canCombine(const FreeVariable& fv) {
        if (fv.varList_.size() != varList_.size()) { return false; }
        return getFreeVarStr() == fv.getFreeVarStr();
    }
    FreeVarible fvMulti(const FreeVarible& lfv, const FreeVarible& rfv) {
        FreeVarible ret;
        if (lfv.coef_ == 0 || rfv.coef_ == 0) { return ret; }
        ret.coef_ = lfv.coef_ * rfv.coef_;
        int l(0), r(0);
        while (l < lfv.varList_.size() || r < rfv.varList_.size()) {
            if (l >= lfv.varList_.size()) { 
                ret.varList_.push_back(lfv.varList_[l++]);
            } else if (r >= rfv.varList_.size()) {
                ret.varList_.push_back(rfv.varList_[r++]);
            } else if (lfv.varList_[l] < rfv.varList>[r]) {
                ret.varList_.push_back(lfv.varList_[l++]);
            } else {
                ret.varList_.push_back(rfv.varList_[r++]);
            }
        }
        ret.isOrdered_ = true;
        return ret;
    }
    string getFreeVarStr() {
        if (!isValid()) { return ""; }
        string ret(to_string(coef_));
        if (!isOrdered_) { adjustVarOrder(); }
        for (const string& var : varList_) {
            ret += '*';
            ret.append(var);
        }
        return ret;
    }
    string getFreeVarKey() {
        if (!isValid()) { return ""; }
        if (varList_.empty()) { return "1"; }
        string ret;
        if (!isOrdered_) { adjustVarOrder(); }
        for (const string& var : varList_) {
            ret.append(var);
            ret += '*';
        }
        ret.pop_back();
        return ret;
    }
    vector<string> varList_;
    bool isOrdered_;
    int coef_;
};
struct Expression {
    Expression() : isSorted_(false) {}
    Expression(int num) : isSorted_(true) {
        freeVarList_.push_back(FreeVarible(num));
        freeVarUst_.insert("1");
    }
    Expression(const string& str) : isSorted_(true) {
        freeVarList_.push_back(FreeVarible({str}));
        freeVarUst_.insert(str);
    }
    ~Expression() { freeValList_.clear(); }
    Expression(const Expression& exp) : isSorted_(exp.isSorted_), freeVarList_(exp.freeVarList_), freeVarUst_(exp.freeVarUst_) {}
    Expression& operator=(const Expression& exp) {
        if (this != &exp) {
            this->isSorted_ = exp.isSorted_;
            this->freeValList_.clear();
            this->freeValList_ = exp.freeValList_;
            this->freeValUst_.clear();
            this->freeValUst_ = exp.freeValUst_;
        }
        return *this;
    }
    Expression convertFromStr(const string& exp, const int beg, const int end, unordered_map<string, int>& ump) {
        Expression ret, loc, now;
        char op('+');
        int num(0);
        string tmp;
        if (beg > end) { return ret; }
        for (int i(beg); i <= end; ++i) {
            if (exp[i] == '(') {
                int rIdx(Util::findRightParaIndex(exp, i, end));
                if (rIdx == -1) { return ret; }
                now = convertFromStr(exp, i, rIdx, ump);
            } else {

            }
        }
    }
    void sortFreeVarList() {
        if (freeValList_.empty()) { return; }
        sort(freeVarList_.begin(), freeVarList_.end(), [](const FreeVarible& l, const FreeVarible& r) {
            if (l.varList_.size() == r.varList_.size()) { return l.getFreeVarKey() < r.getFreeVarKey(); }
            return l.varList_.size() < r.varList_.size();
        });
    }
    bool isValid() { return !freeValList_.empty(); }
    vector<string> getExpressionVec() {
        vector<string> ret;
        if (!isSorted_) { sortFreeVarList(); }
        for (auto& fv : freeVarList_) {
            if (fv.isValid()) { ret.emplace_back(move(fv.getFreeVarStr())); }
        }
        return ret;
    }
    Expression expressionMulti(const Expression& lep, const Expression& rep) {
        Expression ret;
        if (!lep.isValid() || !rep.isValid()) { return ret; }
        return ret;
    }
    vector<FreeVarible> freeVarList_;
    unordered_set<string> freeVarUst_;
    bool isSorted_;
};
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> valUmp;
        int i(0), m(evalvars.size());
        for (i = 0; i < m; ++i) { valUmp[evalvars[i]] = evalints[i]; }

        Expression exp(Expression::convertFromStr(expression, 0, expreesion.size() - 1, valUmp));
        return exp.getExpressionVec();
    }
};
// @lc code=end

