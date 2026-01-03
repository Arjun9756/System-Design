/**
 * Dependecy inversion principle states down that low level module should not communicate with high level module and vice versa also
 * intead of that they should communicate with the help of some intermidary of some interface
 *
 * why ?????
 *
 * Lets say client (Low level)    (SendMail) High Level
 * without intermidary client can make multiple request to SendMail now it may possible that due to netwrok failure the SendMail returns and erro in this case
 * client cannot make the retry mechnaism for failed messages but if we have some intermidiary agent in between which can handle these stuffs easily
 * like retry mechanism and backoff exponentinal
 */

#include <bits/stdc++.h>
using namespace std;

class SendMailService
{
public:
    bool sendMail(string email, string msg)
    {
        try
        {
            cout << "Sending Mail \n";
            return true;
        }
        catch (exception *e)
        {
            return false;
        }
    }
};

class SendMail
{
private:
    SendMailService s1;
    void deadLetterQueue()
    {
        while (!q.empty())
        {
            // Empty The Queue and retry logic
            q.pop();
        }
    }

public:
    queue<pair<string, string>> q;
    bool sendMail(string email, string msg)
    {
        try
        {
            if(!s1.sendMail(email, msg))
                throw new runtime_error("Network Issue");
            return true;
            deadLetterQueue();
        }
        catch (exception *e)
        {
            q.push({email, msg});
            deadLetterQueue();
        }
    }
};

int main()
{
    SendMail s1;
    for (int i = 0; i <= 100; i++)
    {
        s1.sendMail("abc@gmail.com" , "hello");
    }
}