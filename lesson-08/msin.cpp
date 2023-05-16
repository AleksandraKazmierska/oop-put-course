#include <iostream>
#include <vector>

using namespace std;

class Product{
    private:
    string Product_Name;
    double Product_Price;
    public:
    Product(string Name, double Price)
    {
        Product_Name = Name;
    Product_Price =Price;
    }
    
    
    int Product_ID;
    
    public:
   // Product Name(std::string newProduct_Name){
     //   this->Product_Name= std::move(newProduct_Name);
      //  return *this;
//    }
   // Product Price(double newProduct_Price){
      //  this->Product_Price=std::move (newProduct_Price);
      //  return *this;
  //  }
    
    double Cost(){
        return Product_Price;
    }
    
    
};

class Customer{
    private:
    string Customer_Name;
    string Customer_Email;
    int Customer_ID;
    
    public:
     Customer(string Name, double Email,int ID)
    {
        Customer_Name = Name;
    Customer_Email =Email;
    Customer_ID=ID;
    }
    
    Customer Name(std::string newCustomer_Name){
        this->Customer_Name= std::move(newCustomer_Name);
        return *this;}
        
    Customer Email(std::string newCustomer_Email){
        this->Customer_Email= std::move(newCustomer_Email);
        return *this;}
};


class Order{
    private:
    std::vector<Product> products;
    int total_cost;
    Customer customer;
    
    int Order_ID;
    
    Order(int ID,customer)
    {
    Order_ID=ID;
    
    }
    
    double Order_Cost;
    void add_product(Product Name) {
        products.push_back(Name);
        total_cost += Name.Cost();
    };
    int Whole_Price (){
         
        return total_cost;
    };
};

int main()
{
    Product Shoes("Shoes",200);
    
    
    Product Glasses("Sunglasses",100);
   
    
    Order O1(123);
    
    O1.add_product(Shoes);
    O1.add_product(Glasses);
  
   cout<< O1.Whole_Price();
    
    return 0;
}
