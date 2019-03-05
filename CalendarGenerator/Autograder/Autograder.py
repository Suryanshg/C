import os, subprocess, random, difflib


def main():
    print("Autograder for HW1:\n")
    print("Calling 'make'...\n")
    try:
        print(subprocess.run("make clean -C " + os.path.dirname(os.path.abspath(__file__)) + "/../HW1/Debug", stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, shell=True, universal_newlines=True).stdout)
    except subprocess.CalledProcessError as err:
        print(err.stderr, end='')
        return
    try:
        print(subprocess.run("make -C " + os.path.dirname(os.path.abspath(__file__)) + "/../HW1/Debug", stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, shell=True, universal_newlines=True).stdout)
    except subprocess.CalledProcessError as err:
        print(err.stderr, end='')
        return
    print("'make' called successfully!\n")
    four_hundred_years = list(range(2000, 10000, 400))
    one_hundred_years = [year for year in range(1800, 10000, 100) if year not in range(2000, 10000, 400)]
    four_years = [year for year in range(1752, 10000, 4) if year not in range(1800, 10000, 100)]
    common_years = [year for year in range(1752, 10000) if year not in range(1752, 10000, 4)]
    random.seed()
    test_cases = random.choices(common_years, k=4) + random.choices(four_years, k=3) + random.choices(one_hundred_years, k=2) + random.choices(four_hundred_years, k=1)
    print("Start testing...\n")
    passed_cases = 0
    for year in test_cases:
        print("Testing the year of {}...\n".format(year), end='')
        try:
            student_output = subprocess.run(os.path.dirname(os.path.abspath(__file__)) + "/../HW1/Debug/HW1 " + str(year), stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, shell=True, universal_newlines=True).stdout.split("CALENDAR\n", 1)
        except subprocess.CalledProcessError as err:
            print(err.stderr, end='')
            return
        try:
            standard_output = subprocess.run(os.path.dirname(os.path.abspath(__file__)) + "/HW1_std_soln", input=str(year), stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True, shell=True, universal_newlines=True).stdout
        except subprocess.CalledProcessError as err:
            print(err.stderr, end='')
            return
        if len(student_output) < 2:
            print("CALENDAR not found")
            return
        production_output = student_output[1]
        if production_output == standard_output:
            print("PASSED\n")
            passed_cases += 1
        else:
            print("FAILED")
            diff = difflib.ndiff(production_output.splitlines(keepends=True), standard_output.splitlines(keepends=True))
            print(''.join(diff))
    print("You passed {}/10 test case(s).".format(passed_cases))


if __name__ == "__main__":
    main()
