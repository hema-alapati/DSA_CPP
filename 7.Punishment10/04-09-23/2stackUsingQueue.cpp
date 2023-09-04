// https://www.youtube.com/watch?v=jDZQKzEtbYQ

// using 2 queues
class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result = top();
        q1.pop();
        return result;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};
// optimal, only 1 queue
class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
        ;
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int top()
    {
        return q.front();
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
