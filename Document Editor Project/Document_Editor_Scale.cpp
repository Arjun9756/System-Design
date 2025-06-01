#include <bits/stdc++.h>
using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
    ~DocumentElement() {}
};

class TextElement : public DocumentElement
{
public:
    string text;
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return this->text + "\n";
    }
};

class ImageElement : public DocumentElement
{
public:
    string path;
    ImageElement(string path)
    {
        this->path = path;
    }

    string render() override
    {
        return "[Image : " + this->path + " ] \n"; 
    }
};

class Document
{
private:
    vector<DocumentElement *> element;

public:
    void addElement(DocumentElement *documentElement)
    {
        this->element.push_back(documentElement);
    }
    string render()
    {
        string result;
        for (auto element : this->element)
        {
            result += element->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
    ~Persistence() {}
};

class FileStorage : public Persistence
{
public:
    void save(string data)
    {
        // sae to file
    }
};

class DBStorage : public Persistence
{
public:
    void save(string data)
    {
        // Save to DB
    }
};

class DocumentEditor
{
private:
    Document *doc;
    Persistence *pdp;
    string renderedDocument;

public:
    DocumentEditor(Document *doc, Persistence *pdp)
    {
        this->doc = doc;
        this->pdp = pdp;
    }

    void addText(string text)
    {
        doc->addElement(new TextElement(text));
    }
    void addImage(string path)
    {
        doc->addElement(new ImageElement(path));
    }

    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            this->renderedDocument = doc->render();
        }
        return this->renderedDocument;
    }

    void save(Persistence *object)
    {
        if (this->renderedDocument.empty())
        {
            this->renderDocument();
        }

        pdp->save(renderedDocument);
    }
};

int main()
{
    Document *doc = new Document();
    Persistence  *fileStorage = new FileStorage();
    Persistence  *dbStorage = new DBStorage();

    DocumentEditor *editor = new DocumentEditor(doc, dbStorage);
    editor->addText("Hello world");
    editor->addImage("https://arjunportfolios.netlify.app/");
    cout << editor->renderDocument();
}