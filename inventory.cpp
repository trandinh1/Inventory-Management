#include <iostream>
#include <string>

using namespace std;

void addItem(string supplyName[], int inventory[], int& n);
void removeItem(string supplyName[], int inventory[], int& n);
void updateQuantity(string supplyName[], int inventory[], int n);
void sortInventory(string supplyName[], int inventory[], int n);

int main()
{
  //inventory
  int n; 
  int inventory[100];
 
  string supplyName[100];

  cout << "Enter the number of different supplies in inventory: ";
  cin >> n; 
  
  
  cin.ignore();

  //input starting inventory
  for(int i = 0; i < n; i++){
    cout << "Enter Supply Name #" << i + 1<< ": ";
    getline(cin, supplyName[i]);
    cout << "Enter quantity of " << supplyName[i] << " : ";
    cin >> inventory[i]; 
    cin.ignore();
  }
  cout << endl;

  //edit inventory (add item, remove item, update quantity)
  char editSupply;
  while(editSupply != 's'){

    if (n == 0) {
    cout << "Inventory is empty. You can only add items or exit." << endl;
    cin >> editSupply;
    cin.ignore(); 
    if(editSupply != 'a' && editSupply != 's'){
      cout << "Invalid option. Please enter 'a' to add items or 's' to exit." << endl;
      cin >> editSupply;
      cin.ignore();
    }
  } else {
    cout << "Enter 'r' to remove, 'a' to add supply items in inventory, 'u' to update item quanity or 's' if not applicable: ";
    cin >> editSupply;
    cin.ignore(); 
  }
  
    if(editSupply == 'a'){
      addItem(supplyName, inventory, n);
    } else if (editSupply == 'r' && n > 0){
      removeItem(supplyName, inventory, n);
    } else if (editSupply == 'u' && n > 0){
      updateQuantity(supplyName, inventory, n);
    } else if (editSupply == 's') {
      break;
    } else {
      cout << "Invalid option. Please try again." << endl;
    }
    
    
  }
  
  //Sort from lowest quantity to highest quantity
  sortInventory(supplyName, inventory, n);
  
  //Display inventory and quantity
  if(n > 0){
    for(int i=0; i < n; i++){
    cout << supplyName[i] << ": "<< inventory[i] <<endl; 
    }
  } else {
        cout << "Inventory is empty." << endl;
  }
 
  return 0;

}

void addItem(string supplyName[], int inventory[], int& n){
  string name; 
  int quantity; 

  cout << "Enter supply name: ";
  getline(cin, name);
  cout << "Enter quantity of " << name << ": ";
  cin >> quantity; 
  cin.ignore();
  
  n++; 
  supplyName[n - 1] = name;
  inventory[n - 1] = quantity; 
  cout << name << " added to inventory." << endl;
}

void removeItem(string supplyName[], int inventory[], int& n){
  string name; 
  cout << "Enter supply name to be removed: ";
  getline(cin, name);
  bool found = false;
  for(int i = 0; i < n; i++){
    if(supplyName[i] == name){
      for(int r = i; r < n - 1; r++){
        supplyName[r] = supplyName[r + 1];
        inventory[r] = inventory[r + 1];
        }
          found = true;
          n--;
          cout << name << " removed from inventory." << endl;
        }
      }
  if(!found){
    cout << "Supply Invalid." << endl;
  }
}

void updateQuantity(string supplyName[], int inventory[], int n){
  string name; 
  cout << "Enter supply name to update quantity: ";
  getline(cin, name);

  bool found = false; 
    for(int i=0; i<n; i++){
      if(supplyName[i] == name){
        cout << "Enter amount to adjust quantity (positive = add, negative = remove): ";
        int adjustment; 
        cin >> adjustment; 
        cin.ignore();

        inventory[i] += adjustment;
        if(inventory[i] < 0){
          inventory[i] = 0;
          cout << "Invalid quantity. Quanitity set to 0" << endl;
        } else {
          cout << "Quantity of " << name << " updated to " << inventory[i] << endl;
        }

        found = true; 
        break;
        }


        
      }
      if(!found){
      cout << "Supply Invalid." << endl;
      }
}

void sortInventory(string supplyName[], int inventory[], int n){
  for(int i = 0; i < n-1; i++){
    for(int s = i + 1; s < n; s++){
      if(inventory[i] > inventory[s]){
        int temp = inventory[i];
        inventory[i] = inventory[s];
        inventory[s] = temp;

        string tempName = supplyName[i];
        supplyName[i] = supplyName[s];
        supplyName[s] = tempName;
      }
    }
  }  
}