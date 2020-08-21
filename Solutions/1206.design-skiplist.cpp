/*
 * @lc app=leetcode id=1206 lang=cpp
 *
 * [1206] Design Skiplist
 */

// @lc code=start
class Skiplist {
struct Node {
    Node* nxt;
    Node* dwn;
    int val;
    Node() : nxt(nullptr), dwn(nullptr), val(0) {}
    Node(Node* next, Node* down, int value) : nxt(next), dwn(down), val(value) {}
};
public:
    Skiplist() : head(new Node(nullptr, nullptr, -1)) {
        srand(time(nullptr));
    }
    
    bool search(int target) {
        //cout << "search: " << target << endl;
        //print();
        Node* cur(head);
        while (cur != nullptr) {
            while (cur->nxt != nullptr && cur->nxt->val < target) { cur = cur->nxt; }
            if (cur->nxt != nullptr && cur->nxt->val == target) { return true; }
            if (cur != nullptr) { cur = cur->dwn; }
        }
        return false;
    }
    
    void add(int num) {
        //cout << "add: " << num << endl;
        //print();
        Node* cur(head);
        stack<Node*> stk;
        while (cur != nullptr) {
            while (cur->nxt != nullptr && cur->nxt->val < num) { cur = cur->nxt; }
            stk.push(cur);
            if (cur != nullptr) { cur = cur->dwn; }
        }
        Node* down(nullptr);
        while (!stk.empty()) {
            Node* pre(stk.top());
            stk.pop();
            pre->nxt = new Node(pre->nxt, down, num);
            down = pre->nxt;
            if ((rand() & 1) == 0) { break; }
        }
        // add new level
        if (stk.empty() && (rand() & 1) == 1) {
            head = new Node(new Node(nullptr, down, num), head, -1);
        }
    }
    
    bool erase(int num) {
        //cout << "erase: " << num << endl;
        //print();
        Node* cur(head);
        bool ret(false);
        while (cur != nullptr) {
            while (cur->nxt != nullptr && cur->nxt->val < num) { cur = cur->nxt; }
            if (cur->nxt != nullptr && cur->nxt->val == num) {
                ret = true;
                Node* tmp(cur->nxt);
                cur->nxt = cur->nxt->nxt;
                delete tmp;
            }
            if (cur != nullptr) { cur = cur->dwn; }
        }
        return ret;
    }
private:
    void print() {
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node* nod(q.front());
            q.pop();
            if (nod == nullptr) { continue; }
            q.push(nod->dwn);
            while (nod != nullptr) {
                cout << nod->val << ' ';
                nod = nod->nxt;
            }
            cout << endl;
        }
    }
private:
    Node* head;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end

