import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py database/... sequences/...")
        exit(1)
    STRS = []
    profiles = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        STRS = reader.fieldnames[1:]
        for row in reader:
            profiles.append(row)
    strSeq = dict.fromkeys(STRS, 0)
    with open(sys.argv[2], mode="r") as sequence_file:
        sequence = sequence_file.readline()
        for STR in STRS:
            strSeq[STR] = longest_match(sequence, STR)
    for profile in profiles:
        match_count = 0
        for STR in STRS:
            if int(profile[STR]) != strSeq[STR]:
                continue
            match_count += 1
        if match_count == len(STRS):
            print(profile['name'])
            exit(0)
    print("No match")
    exit(1)


def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1

            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


main()
