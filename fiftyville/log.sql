-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First: Looking for a crime scene that match the date of stole.
SELECT description FROM crime_scenes_reports
WHERE day = 28 AND month = 7 AND street = "Humphrey Street";

-- Looking for registers from bakery security between 10:15 and 10:25.
SELECT * FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2023 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Search the plate license.
SELECT person.name from people person
JOIN bakery_security_logs ON person.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
AND bakery_security_logs.year = 2021 AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25;

-- Examine withdraws from ATM.
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7
AND day = 28 AND atm_location = "Leggett Street";

-- Find the account number used in ATM.
SELECT people.name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2023 AND month = 7
AND day = 28 AND atm_location = "Leggett Street";

-- View the phone calls.
SELECT people.name, people.phone_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration <= 60;

-- Seeing the name of airport;
SELECT * FROM airports
WHERE city = 'Fiftyville';

-- Check earliest flight in the next day.
SELECT * FROM flights
WHERE origin_airport_id = 8 AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29;

-- Looking for passenger list.
SELECT people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29
AND flights.hour = 8;

-- Bruce appears in all the lists. Probably is the thief.
-- And now, get the destination of the flight.
SELECT airports.city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = 8
AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8;

-- The destination is New York City.
-- Bruce called to someone. But... Who?
SELECT people.name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration <= 60 AND phone_calls.caller = '(367) 555-5533';

-- Robin is the accomplice.

-- So, Bruce stole the duck, went to New York City and Robin helped him.
