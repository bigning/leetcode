#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void add_items(int item, ListNode* p_list) {
    ListNode* p_tail = p_list;
    while (p_tail ->next != NULL) {
        p_tail = p_tail->next;
    }

    ListNode* new_node = new ListNode(0);
    new_node->val = item;
    new_node->next = NULL;
    p_tail->next = new_node;

}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_list = new ListNode(0);
        ListNode* res_head = res_list;
        res_list->next = NULL;

        ListNode* p_l1 = l1;
        ListNode* p_l2 = l2;
        
        if (l1 == NULL) {
            copy_list(l2, res_list);
            return res_head;
        }
        if (l2 == NULL) {
            copy_list(l1, res_list);
            return res_head;
        }

        int tmp_sum = p_l1->val + p_l2->val;
        int last_add = 0;
        if (tmp_sum >= 10) {
            tmp_sum -= 10;
            last_add = 1;
        }
        res_list->val = tmp_sum;
        p_l1 = p_l1->next;
        p_l2 = p_l2->next;
        while (p_l1 && p_l2) {
            tmp_sum = last_add + p_l1->val + p_l2->val;
            last_add = 0;
            if (tmp_sum >= 10) {
                tmp_sum -= 10;
                last_add = 1;
            }
            ListNode* tmp_node = new ListNode(0);
            tmp_node->next = NULL;
            tmp_node->val = tmp_sum;
            res_list->next = tmp_node;
            res_list = tmp_node;
            p_l1 = p_l1->next;
            p_l2 = p_l2->next;
        }
        if (p_l1 == NULL && p_l2 == NULL) {
            if (last_add == 0) {return res_head;}
            ListNode* tmp_node = new ListNode(0);
            tmp_node->val = 1;
            tmp_node->next = NULL;
            res_list->next = tmp_node;

            return res_head;
        }
        if (p_l1) {
            append_list(p_l1, last_add, res_list);
        }
        else {
            append_list(p_l2, last_add, res_list);
        }
        return res_head;
    }

    void copy_list(ListNode* src, ListNode* dst) {
        ListNode* p_src = src;
        ListNode* p_dst = dst;
        p_dst->val = p_src->val;
        while (p_src->next != NULL) {
            p_src = p_src->next;
            ListNode* p_tmp = new ListNode(0);
            p_tmp->next = NULL;
            p_tmp->val = p_src->val;
            p_dst->next = p_tmp;
            p_dst = p_tmp;
        }
    }

    void append_list(ListNode* l1, int last_add, ListNode* res) {
        if (l1 == NULL) { return; }
        ListNode* tmp_node = new ListNode(0);
        tmp_node->next = NULL;
        int tmp_sum = l1->val + last_add;
        last_add = 0;
        if (tmp_sum >= 10) {
            tmp_sum -= 10;
            last_add = 1;
        }
        tmp_node->val = tmp_sum;
        res->next = tmp_node;
        res = tmp_node;
        while (l1->next != NULL) {
            l1 = l1->next;
            tmp_node = new ListNode(0);
            tmp_node->next = NULL;
            tmp_sum = l1->val + last_add;
            last_add = 0;
            if (tmp_sum >= 10) {
                tmp_sum -= 10;
                last_add = 1;
            }
            tmp_node->val = tmp_sum;
            res->next = tmp_node;
            res = tmp_node;
        }
        if (last_add == 1) {
            ListNode* tmp_node = new ListNode(0);
            tmp_node->val = 1;
            tmp_node->next = NULL;
            res->next = tmp_node;
        }
    }
};

void print_list(ListNode* res) {
    while (res->next != NULL) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << res->val;
    std::cout << std::endl;
}

int main() {
    ListNode* tmp = new ListNode(0);
    tmp->val = 2;
    tmp->next = NULL;
    ListNode* l1 = tmp;
    add_items(4, l1);
    add_items(3, l1);
    add_items(9, l1);
    add_items(9, l1);
    add_items(9, l1);
    add_items(9, l1);
    add_items(9, l1);


    print_list(l1);

    tmp = new ListNode(0);
    tmp->val = 5;
    tmp->next = NULL;
    ListNode* l2 = tmp;
    add_items(6, l2);
    add_items(4, l2);
    add_items(9, l2);
    add_items(8, l2);
    add_items(8, l2);
    add_items(8, l2);
    print_list(l2);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    print_list(res);

    ListNode* res2 = s.addTwoNumbers(l2, l1);
    print_list(res2);

    return 0;
}
