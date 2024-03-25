#include<iostream>
using namespace std;
template<class type>
class Node
{
  public:
  Node():link(NULL){};
  void set_data(type data){this->data=data;}
  void set_link(Node*link){this->link=link;}
  Node* get_link(){return link;}
  type get_data(){return data;}
 private:
 type data;
 Node*link;
};
template<class type>
class LinkedList{
public:
LinkedList():head(NULL),size(0){}
bool is_empty(){return(head==NULL?true:false);} //o(1)
void insert_first(type newitem) //o(1)
{
Node<type>*newnode=new Node<type>;
newnode->set_data(newitem);
if(is_empty()){
 head=newnode;
}else{
Node<type>*old=head;
head=newnode;
newnode->set_link(old);
}
size++;
}
void insert_after(type item,type newitem)  //o(n)
{
Node<type>*temp=head;
while(temp!=NULL){
if(temp->get_data()==item&&temp!=head)
 {
Node<type>*newelement=new Node<type>;
newelement->set_data(newitem);
newelement->set_link(temp->get_link());
temp->set_link(newelement);
size++;
break;
}
else{
temp=temp->get_link();
}
}
}
void insert_before(type item,type newitem) // o(n)
{
 Node<type>* current = head;
 Node<type>* previous = nullptr;
while(current->get_link()!=NULL)
{
if(current->get_data()==item)
 {
previous->set_data(newitem);
previous->set_link(current);
size++;
 break;
 }
previous=current;
current=current->get_link();
}
}
void append(type newitem)// o(n)
{
if(is_empty()){
insert_first(newitem);
}
else{
Node<type>*newnode=new Node<type>;
newnode->set_data(newitem);
Node<type>*temp=head;
while(temp->get_link()){
temp=temp->get_link();
}
temp->set_link(newnode);
size++;
}
}
void delete_first() //o(1)
{
Node<type>*temp=head;
head=temp->get_link();
delete temp;
size--;
}
void delete_end() //o(n)
{
 Node<type>* current = head;
   Node<type>* previous = nullptr;
   while (current->get_link() != nullptr) {
      previous = current;
      current = current->get_link();
        }
        previous->set_link(nullptr) ;
         delete current;
size--;
}
int count() //o(1)
{
return size;
}
void delete_before(type item ) //o(n)
{
  Node<type>*temp=head;
  Node<type>*current=head->get_link();
  current=current->get_link();
  Node<type>*cur;
while(temp!=NULL){
 if(item==current->get_data())
 {cur=temp->get_link();
  temp->set_link(current);
 delete cur;
 break;
 }
current=current->get_link();
temp=temp->get_link();
}
size--;
}
void delete_after(type item) //o(n)
{
  Node<type>*temp=head;
  Node<type>*current=head->get_link();
  current=current->get_link();
  Node<type>*cur;
while(temp!=NULL){
 if(item==temp->get_data())
 {cur=temp->get_link();
   temp->set_link(current);
 delete cur;
 break;
 }
current=current->get_link();
temp=temp->get_link();
}
size--;
}
bool isfind(type item) //o(n)
{
Node<type>*temp=head;
while(temp!=NULL){
if(item==temp->get_data())
return true;

temp=temp->get_link();
}
return false;
}
void replace(type old_item,type new_item) //o(n)
{
Node<type>*temp=head;
bool exist=false;
while(temp!=NULL){
if(old_item==temp->get_data())
{
 exist=true;
 temp->set_data(new_item);
break;
}
temp=temp->get_link();
}
if(exist==false)
cout<<"NOT found";}
void reverse() //o(n)
{
    Node<type>* prev = NULL;
    Node<type>* curr = head;
    Node<type>* next;
while(curr!=NULL){
  next=curr->get_link();
  curr->set_link(prev);
    prev=curr;
    curr=next;
}
head=prev;
}
void display() //o(n)
{
 Node<type>*temp=head;
int n=0;
cout<<"******all element******\n";
while(temp!=NULL){
 n++;
 cout<<"item "<<n<<":"<<temp->get_data()<<endl;
 temp=temp->get_link();
}
}
void displaybyrecursion() //o(n)
{
static Node<type>*temp=head;
static int n=0;
if(temp==NULL)
return ;
else{
n++;
 cout<<"item "<<n<<":"<<temp->get_data()<<endl;
  temp=temp->get_link();
displaybyrecursion();
}
}
private:
int size;
Node<type>*head;
};
int main() {
LinkedList<string>players;

for(int i=0;i<3;i++){
string name;
cout<<"player "<<i+1<<": ";
getline(cin,name);
players.insert_first(name);
}
system("cls");
players.display();
cout<<"Number of players  :"<<players.count()<<endl;
players.delete_first();
players.display();
cout<<"Number of players  :"<<players.count()<<endl;

return 0;
}
