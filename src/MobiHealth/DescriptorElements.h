/*

 * descriptorelements.h

 *

 *  Created on: Feb 11, 2010

 *      Author: Jack

 *      

 *  The package contains a collection of classes that are supposed to represent

 *  a step object. They are an high level abstraction of the elements that

 *  may be found in the xml step configuration file.

 */



#ifndef DESCRIPTORELEMENTS_H_

#define DESCRIPTORELEMENTS_H_



#include <QDomDocument>

#include <vector>



using namespace std;



/* "Element" are all the type of enetities that could be used to build 

 * a step. VOID represents the null element. It's only used to handle exception.
 */

enum Element {TEXT,SELECT,OPTION,MEDIA,IMAGE,RECORDING,INPUTFIELD,VOID};



/* "Position" sed to locate the the label of a text field.

 * 		UP: label over the textfield

 * 		DOWN: label below the textfield

 * 		LEFT: label left to the textfield

 * 		RIGHT: label right to the textfield
 */

enum Position {UP,DOWN,LEFT,RIGHT};



/* It represents the common features among al the elements. */

class StepGenericElement

{

public:

	StepGenericElement(QString type_in, QString id_in, Element el_in, QString content_in ="");

	virtual ~StepGenericElement();

	

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



/* It's a generic text field box */

class Text : public StepGenericElement

{

public: 

	Text(QString type_in, QString id_in, float width_in, int rows_in, QString content_in ="", Element el_in = TEXT);

	virtual ~Text();

	

	float getWidth();

	int getRows();

	

protected:

	float width;

	int rows;

};



/* It's an text field with a label associated. The label can be located using the

 * "Position" type.
 */

class Input : public Text

{

public:

	Input(QString type_in, QString id_in, float width_in, int rows_in, QString label_in, Position pos_in, QString content_in ="");	

	virtual ~Input();

	

	QString getLabel();

	Position getPos();

	

protected:

	QString label;

	Position pos;

};





/* It represents a multiple choice list. Choices can be mutually exclusive or not.

 * Each choice of the select element has a list of "Option".
 */

class Select : public StepGenericElement{



	public:

	

		Select(QString type_in, QString id_in, bool mutex, QString content_in ="", Element el_in = SELECT);	

		virtual ~Select();

	

		/* It's a choice of a Select.

		 * The value field should be the returing value of the field, but

		 * the qt "radio button" doesn't allow to set such a field, so,

		 * at the moment, it's totally pointless. The returned value, for now,

		 * the content of the element.

		 */

		class Option : public StepGenericElement{

			friend class Select;

			public:

		

				Option(QString type_in, QString id_in, QString value_in, QString content_in ="");	

				virtual ~Option();

				

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



/* It represents a generic media (that could an image, a sound o whatever you want).

 * The "take" attribute, if it's set to true, indicates that the media is supposed

 * to be taken by the device.
 */

class Media : public StepGenericElement{

public :

	Media(QString type_in, QString id_in, QString caption_in, bool take_in, QString content_in ="", Element el_in = MEDIA);	

	virtual ~Media();



	bool isTake();

	

	QString getCaption();

	

protected:

	bool take;

	QString caption;

};



class Image : public Media{

public:

	Image(QString type_in, QString id_in, QString caption_in, bool take_in, float width_in, float height_in, QString content_in ="");	

	
	virtual ~Image();

	

	float getWidth();

	float getHeight();

	

protected:

	float width;

	float height;

};





/* It's the element representing a recording. The "dur" attribute  is the duration

 * of the recording.
 */

class Recording : public Media{

public:

	Recording(QString type_in, QString id_in, QString caption_in, bool take_in, float dur = 0.0, QString content_in ="");	

	virtual ~Recording();

	

	float getDur();

	

protected:

	float dur;

};



#endif /* DESCRIPTORELEMENTS_H_ */

