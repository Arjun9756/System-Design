#include <bits/stdc++.h>
using namespace std;

class DocumentEditor
{
private:
    vector<string> documentElement;
    string renderDocument;

public:
    DocumentEditor()
    {
        // Constructor function
    }

    void addText(string text)
    {
        if (text.size() <= 0)
            return;
        this->documentElement.push_back(text);
    }

    void addImage(string path)
    {
        if (path.size() < 5)
        {
            return;
        }

        this->documentElement.push_back(path);
    }

    void renderDocumentScreen()
    {
        if (renderDocument.empty())
        {
            string result;
            for (auto element : this->documentElement)
            {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 4) == ".png"))
                {
                    result += "[Image: " + element + "]\n";
                }
                else
                {
                    result += element + "\n";
                }
            }

            this->renderDocument = result;
            cout << this->renderDocument;
        }
    }

    void saveToFile()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            this->renderDocumentScreen();
            file << this->renderDocument;
            file.close();

            cout << "Saved to file \n";
        }
        else
        {
            cout << "Error while opening the file \n";
        }
    }
};

int main()
{
    DocumentEditor *e1 = new DocumentEditor();
    e1->addImage("picture.png");
    e1->addText("hello world");

    e1->saveToFile();
}