/*
 * doctors_office.cpp
 *
 * This class represents a doctor's office in a queuing system, mainly a wrapper for a vector of doctor objects.
 */

#include "doctors_office.h"

// Constructor for a doctor's office.
doctors_office::doctors_office(int num_docs)
{   
    this->num_doctors = num_docs;
    doctors.resize(num_doctors);    //Initialised with size num_doctors
    
}

// Detrcutor for doctors_office.
doctors_office::~doctors_office()
{

}

// Search the list of doctors for the first free doctor, then return doctor'sID
int doctors_office::get_free_doctor_ID() const
{
    for (int i = 0; i < num_doctors; ++i) {
        if (doctors[i].is_free()) {
            return i;
        }
    }
    return -1;
}

// Get the number of doctors that are busy.
int doctors_office::get_number_of_busy_doctors() const
{
    int count_busy_doctors = 0;
    for (int i=0; i < num_doctors; i++) {
        if(!doctors[i].is_free()) {
            count_busy_doctors++;
        }
    }
    return count_busy_doctors;
}

// Set a doctor as busy with the specified patient.
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat, int app_time)
{
    if(doc_ID >= 0 && doc_ID < num_doctors) {
        doctors[doc_ID].set_current_patient(pat);
        doctors[doc_ID].set_remaining_appointment_time(app_time);
        doctors[doc_ID].set_busy();
    }
}

// Set a doctor as busy with the specified patient.
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat) {
    if(doc_ID >= 0 && doc_ID < num_doctors) {
        doctors[doc_ID].set_current_patient(pat);
        doctors[doc_ID].set_busy();
    }
}

// Update the status of doctors, checking if they have become free.
void doctors_office::update_doctors(int time)
{
    for(int i=0; i< num_doctors; ++i) {
        //Decrease the remaining appointment time by 1 unit
        if(!doctors[i].is_free()) {
            int remaining_time = doctors[i].get_remaining_appointment_time() - 1 ;  
            doctors[i].set_remaining_appointment_time(remaining_time);            
        
        //If remaining_time of a busy doctor <= 0 , the doctor is set to "free".
        if(remaining_time <= 0) {
                doctors[i].set_free();  
                display_appointment_done(i, doctors[i].get_current_patient_number(), time );
            }
        }   
    }
}
