class ProductOfNumbers {
public:
    vector<int> prefProd;
        int size=0;
    ProductOfNumbers() {
       prefProd.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            prefProd.clear();
            prefProd.push_back(1);
            return ;
        }
         prefProd.push_back(prefProd.back() * num);
    }
    
    int getProduct(int k) {
        int size=prefProd.size();
        if(size<=k){
            return 0;
        }
        else{
            return prefProd[size-1] / prefProd[size-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */