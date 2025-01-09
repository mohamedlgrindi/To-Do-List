#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Task{
private:

string description;
bool status;

public:

 Task(string des , bool st){
  description=des;
  status=st;
 }

void MarkComplite(){
  status=true;
}

void DisplayTask(){
    cout<<"     "<<"Task description: "<<description<<endl;
    if (status)
    {
        cout<<"     "<<"Task status: COMPLETED"<<endl;
    }
    else{
        cout<<"     "<<"Task status: Pending"<<endl;
    }
}

std::string get_describtion(){
    return description;
}
bool get_statu(){
       if (status)
    {
        cout<<" COMPLETED"<<endl;
        return true;
    }
    else{
        cout<<"Pending"<<endl;
        return false;
    }
}
};

class Todolist{
  
  private:
  vector<Task>Tasks;
  
  public:

  void addTask(string description,bool statu){
   Task newTask(description,statu);
   Tasks.push_back(newTask);
  }
  
  void deleteTask(int index){
         if (index >= 0 && index < Tasks.size()) {
            Tasks.erase(Tasks.begin() + index);
            cout << "____Deleting successfully____" << endl;
        } else {
            cout << "Invalid index!" << endl;
        }
  }

  void ShowTasks(){

    for (int i = 0; i < Tasks.size(); i++)
    {
        cout<<"Task "<<i+1<<endl;
        /*cout<<"TASK DESCRIPTION: "<<Tasks[i].get_describtion()<<endl;
        cout<<"TASK STATU: "<<endl;*/
        Tasks[i].DisplayTask();
        cout<<endl;
    }
    
  }

  void ClearComplete(){
    for (int i = 0; i < Tasks.size();)
    {
        if(Tasks[i].get_statu()){
            Tasks.erase(Tasks.begin()+i);
        }
        else{
           i++;
        }
    }
    cout<<"____Tasks copleted are deleted____"<<endl;
  }

};

int main(){

    int op;
    Todolist taskmanager;
    do{
      cout<<"0. Exit"<<endl;  
      cout<<"1. Add Task"<<endl;
      cout<<"2. Delete Task"<<endl;
      cout<<"3. Show Tasks"<<endl;
      cout<<"4. Clear Completed"<<endl;
      cout<<"5. Clear scring"<<endl;
      cin>>op;
      cin.ignore();
      switch(op){
         case 0:
         break;

         case 1 :{
           std:: string describ;
           bool statu;
           cout<<"Enter the task Describtion:"<<endl;
           getline(cin,describ);
           cout<<"Enter the task statu:"<<endl;
           cout<<"Enter 1 for completed or 0 for pending"<<endl;
           cin>>statu;
           taskmanager.addTask(describ,statu);

           cout<<"____Task added successfuly____"<<endl;
           break;
           }
           

          case 2 :{
          int index;
          cout<<"enter the index of the  Task:"<<endl;
          cin>>index;
          index-=1;
          taskmanager.deleteTask(index);
          break; 
          }

          
          case 3 :{
           taskmanager.ShowTasks();
           cout<<"____Tasks desplayed succssefuly____"<<endl;
           break;
          }
           

          case 4 :
          taskmanager.ClearComplete();
          break;

          case 5 :
          system("cls");
          break;

          default:
          cout<<"_____try again_____"<<endl;
          break;

      }

    }while(op!=0);

    return 0;
}