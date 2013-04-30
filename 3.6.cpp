//使用一个附加的栈来模拟插入排序
stack<int> Ssort(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        int data = s.top();
        s.pop();
        while(!t.empty() && t.top()>data){
            s.push(t.top());
            t.pop();
        }
        t.push(data);
    }
    return t;
}

//使用一个优先队列来为出栈的元素排序
void Qsort(stack<int> &s){
    priority_queue< int,vector<int>,greater<int> > q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}

