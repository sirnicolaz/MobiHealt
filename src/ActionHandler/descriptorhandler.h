#ifndef DESCRIPTORHANDLER_H
#define DESCRIPTORHANDLER_H


#include <QDomDocument>
#include <QFile>

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Element {TEXT,SELECT,OPTION,MEDIA,IMAGE,RECORDING,INPUTFIELD};
enum Position {UP,DOWN,LEFT,RIGHT};

class DescriptorHandler
{

public:
    DescriptorHandler(QString fileName);
    ~DescriptorHandler();
    QString getActionId();
    QString getActionTitle();

    QString getStepID(int stepNumber);
    
    QString getStepType(int stepNumber);
    QString getStepType(QString ID);
    
    QString getStepTitle(int stepNumber);
    QString getStepTitle(QString ID);
    
    QString getStepChildType(int stepNumber, int childNumber);
    QString getStepChildType(QString stepID, int childNumber);
    QString getStepChildType(int stepNumber, QString childID);
    QString getStepChildType(QString stepID, QString childID);
    
    QString getStepChildContent(int stepNumber, int childNumber);
    QString getStepChildContent(int stepNumber, QString tag, int number = 0);
    QString getStepChildTagName(int stepNumber, int childNumber);

private:
    QDomDocument *doc;

protected:
    QDomElement getStep(int stepNumber);
};

class StepGenericElement
{
public:
	StepGenericElement(QString type_in, QString id_in, Element el_in, QString content_in ="");
	~StepGenericElement();
	
	virtual QString getType();
	virtual QString getId();
	virtual QString getElementName();
	virtual QString getContent();
	
protected:
	QString type;
	QString id;
	Element el;
	QString content;
};

class Text : public StepGenericElement
{
public: 
	Text(QString type_in, QString id_in, float width_in, int rows_in, Element el_in = TEXT, QString content_in ="");
	~Text();
	
	float getWidth();
	int getRows();
	
protected:
	float width;
	int rows;
};

class Input : public Text
{
public:
	Input(QString type_in, QString id_in, float width_in, int rows_in, QString label_in, Position pos_in, QString content_in ="");	
	~Input();
	
	QString getLabel();
	Position getPos();
	
protected:
	QString label;
	Position pos;
};

class Select : public StepGenericElement{

	public:
	
		Select(QString type_in, QString id_in, bool mutex, Element el_in = SELECT, QString content_in ="");	
		~Select();
	
		class Option : public StepGenericElement{
			friend class Select;
			public:
		
				Option(QString type_in, QString id_in, QString tag_in, QString content_in ="");	
				~Option();
				
				bool isSelected();
				QString getValue();
				void setFather(Select * father_in);
				void setSelected(bool selected_in);
				
			protected:
				Select * father;
				bool selected;
				QString value;
		};
		
		Option getOption(int num);
		Option getOption(QString ID);
		//TODO: Hide base class getContent. That's ok because Select element is supposed to have only options as content.
		vector<Option> getOptions();
		bool isMutex();
		
		void addOption(Option opt_int);
		
	protected:
		bool mutex;
		vector<Option> options_list;
		
};

class Media : public StepGenericElement{
public :
	Media(QString type_in, QString id_in, QString caption_in, bool take_in, Element el_in = MEDIA, QString content_in ="");	
	~Media();

	bool isTake();
	
	QString getCaption();
	
protected:
	bool take;
	QString caption;
};

class Image : public Media{
public:
	Image(QString type_in, QString id_in, QString caption_in, bool take_in, float width_in, float height_in, QString content_in ="");	
	~Image();
	
	float getWidth();
	float getHeight();
	
protected:
	float width;
	float height;
};

class Recording : public Media{
public:
	Recording(QString type_in, QString id_in, QString caption_in, bool take_in, float dur = 0.0, QString content_in ="");	
	~Recording();
	
	float getDur();
	
protected:
	float dur;
};

#endif // DESCRIPTORHANDLER_H
