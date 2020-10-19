
author : sourabh kumar
date created : 19 oct , 2020

Ques. statement : Given two numbers represented by two linked lists, write a function that returns Sum list. 
                  The sum list is linked list representation of addition of two input numbers.

ex:

S1 = 3, S2 = 3
ValueS1 = {2,3,4}
ValueS2 = {3,4,5}
Output: 5 7 9
Explanation: After adding the 2 numbers
the resultant number is 5 7 9.

//************************************************************************************************************************************************************************

//Recursive approach


Node* addSameSize(Node* head1, Node* head2, int* carry) 
{ 
    if(head1->next == NULL)
    {
        int val = head1->data + head2->data + *carry;
        head1->data = val % 10;
        *carry  = val /10;
        
        return head1;
    }
    
    addSameSize(head1->next , head2->next , carry);
    
    int val = head1->data + head2->data + *carry;
    head1->data = val % 10;
    *carry = val/10;
    
    return head1;
    
} 

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result) 
{ 
    if(head1->next == curr)
    {
        int val = head1->data + *carry;
        head1->data = val%10;
        *carry = val/10;
        *result = head1;
         return;
    }
    
    addCarryToRemaining(head1->next , curr , carry , result);
    
    
        int val = head1->data + *carry;
        head1->data = val%10;
        *carry = val/10;
        
        *result = head1;
}



//************************************************************************************************************************************************************************

//Iterative approach

Node* addSameSize(Node* head1, Node* head2, int* carry)     // for adding LL till same size.
{ 
    stack<Node*> s1 , s2;        //used stack to add in reverse manner.
    
    Node *start1 = head1 ,  *start2 = head2;
    
    while(start1 != NULL) {s1.push(start1); start1 = start1->next; }   // pushing all addresses of both LL
    while(start2 != NULL) {s2.push(start2); start2 = start2->next; }
    
    int val;
    
    while(!s1.empty())    // one by adding all nodes and storing into first LL , at the same time maintaining querry.
    {
        Node* t1 = s1.top();  s1.pop();
        Node* t2 = s2.top();  s2.pop();
        
        val = t1->data + t2->data + *carry;
        
        if(val  >= 10)
          *carry = val / 10;
        else 
          *carry = 0;
        
        t1->data = val%10;
    }
    
    return head1;
} 

void addCarryToRemaining(Node* head1, Node* curr, int* carry, Node** result)   // function to add remaining nodes , i.e extra length
{ 
    int val;
    Node* start = head1;
    
    stack<Node*> s;
    
    while(start != curr) {s.push(start); start = start->next; }
    
    while(!s.empty())
    {
        Node* t = s.top();  s.pop();
        
        val = t->data + *carry;
        
        if(val >= 10)
          *carry = val / 10;
        else 
          *carry = 0;
        
        t->data  = val%10;
    }
    
    *result = head1;   // storing the resultand LL address in result.
}

