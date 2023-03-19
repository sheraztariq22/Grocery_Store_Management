#pragma once
#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <iostream>
#include <string>
using namespace std;

class Feedback 
{
private:
	int appId;
	char feedback[100];
	char reply[100];
	float rating;
public:
	Feedback(int id = 1, string fbk = "NULL", string rpy = "NULL");
	void setAppId(int id);
	void setFeedback(string f);
	void setReply(string r);
	int getAppId();
	string getFeedback();
	string getReply();
	void setRating(float _r);
	float getRating();
	friend ostream& operator<<(ostream& output, const Feedback& fb);
	~Feedback();
};

Feedback::Feedback(int id, string fbk, string rpy) {
	appId = id;
	rating = 0;
	strcpy_s(feedback, fbk.c_str());
	strcpy_s(reply, rpy.c_str());
}
void Feedback::setFeedback(string f) {
	strcpy_s(feedback, f.c_str());
}
void Feedback::setAppId(int id) {
	appId = id;
}
void Feedback::setReply(string r) {
	strcpy_s(reply, r.c_str());
}
int Feedback::getAppId() {
	return appId;
}
string Feedback::getFeedback() {
	return feedback;
}
string Feedback::getReply() {
	return reply;
}
void Feedback::setRating(float _r) {
	rating = _r;
};
float Feedback::getRating() {
	return rating;
}

ostream& operator<<(ostream& output, const Feedback& fb) {
	cout << "FEEDBACK: " << fb.feedback << "     Rating: " << fb.rating << "     response > " << fb.reply;
	return output;
}
Feedback::~Feedback() {

}
#endif // FEEDBACK_H