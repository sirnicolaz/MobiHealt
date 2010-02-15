/*
 * descriptorelements.h
 *
 *  Created on: Feb 11, 2010
 *      Author: Jack
 */

#ifndef DESCRIPTORELEMENTS_H_
#define DESCRIPTORELEMENTS_H_

#include <QDomDocument>
#include <vector>

using namespace std;

enum Element {TEXT,SELECT,OPTION,MEDIA,IMAGE,RECORDING,INPUTFIELD,VOID};
enum Position {UP,DOWN,LEFT,RIGHT};

class StepGenericElement
{
public:
	StepGenericElement(QString type_in, QString id_in, Element el_in, QString content_in ="");
	//~StepGenericElement();
	
	virtual QString getType();
	virtual QString getId();
	virtual Element getElementName();
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
	Text(QString type_in, QString id_in, float width_in, int rows_in, QString content_in ="", Element el_in = TEXT);
	//~Text();
	
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
	//~Input();
	
	QString getLabel();
	Position getPos();
	
protected:
	QString label;
	Position pos;
};

class Select : public StepGenericElement{

	public:
	
		Select(QString type_in, QString id_in, bool mutex, QString content_in ="", Element el_in = SELECT);	
		//~Select();
	
		class Option : public StepGenericElement{
			friend class Select;
			public:
		
				Option(QString type_in, QString id_in, QString value_in, QString content_in ="");	
				//~Option();
				
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
	Media(QString type_in, QString id_in, QString caption_in, bool take_in, QString content_in ="", Element el_in = MEDIA);	
	//~Media();

	bool isTake();
	
	QString getCaption();
	
protected:
	bool take;
	QString caption;
};

class Image : public Media{
public:
	Image(QString type_in, QString id_in, QString caption_in, bool take_in, float width_in, float height_in, QString content_in ="");	
	//~Image();
	
	float getWidth();
	float getHeight();
	
protected:
	float width;
	float height;
};

class Recording : public Media{
public:
	Recording(QString type_in, QString id_in, QString caption_in, bool take_in, float dur = 0.0, QString content_in ="");	
	//~Recording();
	
	float getDur();
	
protected:
	float dur;
};

#endif /* DESCRIPTORELEMENTS_H_ */
