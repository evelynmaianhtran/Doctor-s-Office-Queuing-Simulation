/*
 * doctor.cpp
 * Written by : Mai Anh Tran (c3427150)
 * Modified : 12/04/2024
 *
 * This class represents a doctor in a queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#include "doctor.h"

// Constructor for a doctor.
doctor::doctor()
{
    is_busy = false;    //Set dctor's status is free
    remaining_appointment_time = 0;
}

// Detructor for a doctor.
doctor::~doctor()
{

}

// Determine if the doctor is free.
bool doctor::is_free() const
{
    if(is_busy)     return false;
    else            return true;
}

// Set the status of the doctor to busy.
void doctor::set_busy()
{
    is_busy = true;
}

// Set the status of the doctor to free.
void doctor::set_free()
{
    is_busy = false;
}

// Set the remaining appointment time according to the parameter.
void doctor::set_remaining_appointment_time(int t)
{
    remaining_appointment_time = t;
}

// Set the remaining appointment time according to the patient.
void doctor::set_remaining_appointment_time()
{
    remaining_appointment_time = current_patient.get_appointment_length();
}

// Return the remaining time in the current appointment.
int doctor::get_remaining_appointment_time() const
{
    return remaining_appointment_time;
}

// Decrement the time remaining in the current appointment by 1 unit.
void doctor::decrement_remaining_appointment_time()
{
    remaining_appointment_time--;
}

// Set the current patient to the supplied patient.
void doctor::set_current_patient(const patient& pat)
{
    current_patient = pat;
}

// Return the patient number of the current patient.
int doctor::get_current_patient_number() const
{
    return current_patient.get_patient_number();
}

// Return the arrival time of the current patient.
int doctor::get_current_patient_arrival_time() const
{
    return current_patient.get_arrival_time();
}

// Return the waiting time of the current patient.
int doctor::get_current_patient_waiting_time() const
{
    return current_patient.get_waiting_time();
}

// Return the appointment time of the current patient.
int doctor::get_current_patient_appointment_length() const
{
    return current_patient.get_appointment_length();
}