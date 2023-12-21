class MyCircularDeque {
public:

    int size, front, rear, *arr;

    MyCircularDeque(int k) {
        size = k;
        front = rear = -1;
        arr = new int[size];

    }
    
    bool insertFront(int value) {
        
        if(isFull()){ //overflow
            return false;
        }else if(front==-1 && rear==-1){//empty case --> front++ Rear ++ arr[front] = val
            front++;
            rear++;
            arr[front]= value;
        }else if(front==0 && rear != size-1){//circular case --> front = 0 and rear != size-1
            front=size-1;
            arr[front] = value;
        }else{//normal case --> front -- and arr[front] = val
            front--;
            arr[front] = value;
        }

        return true;    

    }
    
    bool insertLast(int value) {
        
        //overflow
        //empty
        //circular
        //normal

        if(isFull()){
            return false;

        }else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[rear] = value;

        }else if(rear==size-1 && front!= 0){
            rear = 0;
            arr[rear] = value;

        }else{
            rear++;
            arr[rear] = value;

        }

        return true;

    }
    
    bool deleteFront() {
        
        //isempty
        //single ele case --> front==rear
        //circular case --> front == size-1 then front=0
        //normal a[front] = -1 and f++;

        if(isEmpty()){
            return false;
        }else if(front == rear){

            arr[front]=-1;
            front = -1;
            rear = -1;

        }else if(front == size-1){
            arr[front] =-1;
            front=0;
        }else{
            arr[front] = -1;
            front++;
        }

        return true;
    }
    
    bool deleteLast() {

        //isempty
        //single ele
        //circular
        //normal

        if(isEmpty()){
            return false;
        }else if(front == rear){
            front = -1;
            rear = -1;

        }else if(rear == 0){
            rear = size-1;

        }else{
            rear--;
        }

        return true;
        
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[front];
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {

        return front==-1 && rear==-1; //agar condition satisfy hua to true warna false
        
    }
    
    bool isFull() {
        return (front==0 && rear==size-1) || (rear == front-1);
        //agar condition satisfy hua to true warna false
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */