/*
 * simulation.cpp
 * Written by : Mai Anh Tran (c3427150)
 * Modified : 12/04/2024
 *
 * This class represents the simulation in a doctor's office queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#include "simulation.h"

// Contructor for simulation
simulation::simulation(int sim_time, int num_doctors, int appointment_time, int time_between_arrival)
{
    this->sim_time = sim_time;
    this->num_doctors = num_doctors;
    this->appointment_time = appointment_time;
    this->time_between_arrival = time_between_arrival;
    this->total_wait_time = 0;    
    this->patients_arrived = 0;   
    office = doctors_office(num_doctors);
}

// Detructor for simulation
simulation::~simulation()
{

}

// Run the simulation.
void simulation::run_simulation()
{
    for (int current_time = 0; current_time < sim_time; ++current_time) {
        // Update doctor's office status
        office.update_doctors(current_time);    

        // If waiting_queue is non-empty, increment the waiting time of each patient by 1
        LQueue<patient> new_queue;
        while (!waiting_queue.empty()) {
            patient p = waiting_queue.dequeue();   //Delete the last patient from waiting_queue, return that patient as p
            p.increment_waiting_time();            //Increase the waiting time by 1
            new_queue.enqueue(p);                  // Add p to the rear of the new_queue
        }
        waiting_queue = new_queue;                 //Restore the queue

        // Modify the queue when new patients arrived
        if (has_patient_arrived(time_between_arrival)) {
            int patient_num = patients_arrived;    //Set patient number
            patient new_patient = patient();      
            new_patient.set_patient_info(patient_num, current_time, 0, appointment_time);               
            display_patient_arrived(new_patient.get_patient_number(), current_time); 
            patients_arrived++;                    //Increase the number of patients by 1           
            waiting_queue.enqueue(new_patient);    //Add new patient to the queue
        }

        // Send new_patient to the free doctor if there is a free doctor and the patient queue is non-empty,
        while(office.get_free_doctor_ID() != -1 && !waiting_queue.empty()) {           
            patient current_patient = waiting_queue.dequeue();              //Remove and return a patient from the front of the queue
            total_wait_time += current_patient.get_waiting_time();          //Increase the total waiting time     
            display_patient_seen(office.get_free_doctor_ID(), current_patient.get_patient_number(), current_time); 
            office.set_doctor_busy(office.get_free_doctor_ID(), current_patient, appointment_time);  //Send the patient to the free doctor  
        }
    }
}

// Return a reference to the doctor's office used in the simulation.
doctors_office& simulation::get_office()
{
    return office;   
}

// Return a reference to the patient queue used in the simulation.
LQueue<patient>& simulation::get_patient_queue()
{   
    return waiting_queue;
}

// Return the total time patients spent waiting during the simulation.
int simulation::get_total_wait_time()
{   
    return total_wait_time;   
}

// Return the numer of patients that arrived throughout the simulation.
int simulation::get_num_patients_arrived()
{   
    return patients_arrived;    
}