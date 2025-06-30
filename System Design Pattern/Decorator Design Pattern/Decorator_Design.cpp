// Descorator design pattern ek esa pattern hota h jo kisi ek object ko addtitional functionality or features provide krta h bina uske
// code ko modify kre

//  Exmaple apne youtube per video upload kardi wo ek alg object hogya ab iske uper video quality adjust krna speed , captain , watermark , compressed
// ye sav additional features hogye inko provide karne ke liye hum yha per decorator ka use krna pdega

// Ab ye toh inheritance se bhi ho skta h lekin inheritance ki ye problem h ki isme problem of class exploision hota h mtlw features ko add on krne ke liye
// hum alg alg classes bnate h jise un subclasses ko manage karne bhot difficult hota h

// YE basically has a or is a realtion donu ko use krta h has a for compositon for adding fetaures and is a to behave like that object

#include <bits/stdc++.h>
using namespace std;

class Video
{
public:
    virtual string process() = 0;
};

class RawVideo : public Video
{
public:
    string process()
    {
        return "Raw Video";
    }
};

class VideoDecorator : public RawVideo
{
public:
    Video *base;
    VideoDecorator(Video *v)
    {
        this->base = v;
    }
};

class EncryptDecorator : public VideoDecorator
{
public:
    EncryptDecorator(Video *v) : VideoDecorator(v) {}
    string process() override
    {
        return "Encrypted (" + base->process() + ")";
    }
};

class CompressDecorator : public EncryptDecorator
{
public:
    CompressDecorator(Video *v) : EncryptDecorator(v){}
    string process() override
    {
        return "Compressed (" + base->process() + ")";
    }
};

int main()
{
    Video *video = new RawVideo();
    video = new EncryptDecorator(video);
    video = new CompressDecorator(video);
    cout << video->process();
}