# DentalClinic

This is a project for the subject Programming Technique 2. In this project, our team decided to make Dental Clinic Management for 
Covid-19.

################### TO-DO LISTS ###################

1. Create input.txt (list o) **
   -5 nurse
   -2 dentist
   -5 past patients (mix decline and accepted appointments)

2. Create output.txt (storing previous session's info) **
3. Put class definitions on top of the program
4. Function to update current patient's information
    (access specific patient's info and edit)
5. Add appointment date
6. Schedule list
7. Implement operator overloading and polymorphism where possible. **
8. Desigm more attractive interface (main menu, output template,etc) **
9. Update UML Diagram based on code **
10. Apa yg patut. 

Patient
- addAppointmentTime()

Dentist
- constructor to initialize from input.txt
- ????

Nurse
- constructor to initialize from input.txt
- ????

Appointment
- ???? (Discuss)


################### HOW IT WORKS ###################
1. patient sets an appointment date
2. if appointment date is empty, nurse will update the patient record (name,age ,etc).
3. nurse screens the patient and determine whether the patient is suitable for treatment (temp, illness)
	- if temp is higher than 37.5 then cancel appointment

4. nurse updates patient's current temperature and symptoms in patient record
5. dentist treats patient.
6. nurse update the medicine , symptoms and instruction of patient



################### MENU ###################
1. Add new patient
2. Update patient record
3. View schedule (appointment dates)
4. View patient details
5. View staff details
6. Exit 
