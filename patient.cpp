/*
 * patient.cpp
 * This class represents a patient in a queuing system.
 */

#include "patient.h"

//Contructor for patient.
patient::patient(int pat_num, int arrival_time, int wait_time, int app_length) 
{
    this->patient_number = pat_num;
    this->arrival_time = arrival_time;
    this->waiting_time = wait_time;
    this->appointment_length = app_length;

}

//Detructor for patient.
patient::~patient()
{

}

// Update the patient information using the supplied values.
void patient::set_patient_info(int pat_num, int arrive_time, int wait_time, int app_length)
{
    this->patient_number = pat_num;
    this->arrival_time = arrival_time;
    this->waiting_time = wait_time;
    this->appointment_length = app_length;
}

// Return waiting time.
int patient::get_waiting_time() const
{
    return waiting_time;
}

// Set the waiting time to the specified value.
void patient::set_waiting_time(int time)
{
    waiting_time = time;
}

// Increment the waiting time by 1 unit.
void patient::increment_waiting_time()
{
    waiting_time++;
}

// Return the arrival time.
int patient::get_arrival_time() const
{
    return arrival_time;
}

// Return the appointment length.
int patient::get_appointment_length() const
{
    return appointment_length;
}

// Return the patient number.
int patient::get_patient_number() const
{
    return patient_number;
}
