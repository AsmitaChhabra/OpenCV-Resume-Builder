#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

// Function to draw headers with black color
void drawHeader(cv::Mat &image, const std::string &text, int x, int y, double fontScale = 1.5, cv::Scalar color = cv::Scalar(0, 0, 0)) {
    int font = cv::FONT_HERSHEY_DUPLEX;
    int thickness = 2;
    cv::putText(image, text, cv::Point(x, y), font, fontScale, color, thickness, cv::LINE_AA);
}

// Function to draw text sections with dark grey color
void drawSection(cv::Mat &image, const std::string &text, int x, int y, double fontScale = 0.7, cv::Scalar color = cv::Scalar(50, 50, 50)) {
    int font = cv::FONT_HERSHEY_DUPLEX;
    int thickness = 1;
    cv::putText(image, text, cv::Point(x, y), font, fontScale, color, thickness, cv::LINE_AA);
}

// Function to insert the user's photo into the resume
void addPhoto(cv::Mat &resumeImage, const std::string &photoPath, int x, int y, int width, int height) {
    cv::Mat photo = cv::imread(photoPath);
    if (!photo.empty()) {
        cv::resize(photo, photo, cv::Size(width, height));
        photo.copyTo(resumeImage(cv::Rect(x, y, photo.cols, photo.rows)));
    } else {
        std::cout << "Error: Could not load photo from " << photoPath << std::endl;
    }
}

int main() {
    cv::Mat resumeImage(1200, 1000, CV_8UC3, cv::Scalar(255, 255, 255));

    std::string name, email, phone, summary, skills, college, degree, workExperience, achievements, projects, photoPath;
    std::cout << "Enter your Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter your Phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter your Summary: ";
    std::getline(std::cin, summary);
    std::cout << "Enter your Skills (comma-separated): ";
    std::getline(std::cin, skills);
    std::cout << "Enter your College: ";
    std::getline(std::cin, college);
    std::cout << "Enter your Degree: ";
    std::getline(std::cin, degree);
    std::cout << "Enter your Work Experience: ";
    std::getline(std::cin, workExperience);
    std::cout << "Enter your Achievements: ";
    std::getline(std::cin, achievements);
    std::cout << "Enter your Projects (use \\n for line breaks): ";
    std::getline(std::cin, projects);

    std::cout << "Enter the path to your photo in jpg format: ";
    std::getline(std::cin, photoPath);

    addPhoto(resumeImage, photoPath, 750, 50, 200, 200);

    drawHeader(resumeImage, "Professional Resume", 250, 80);
    drawSection(resumeImage, "Name: " + name, 50, 150, 0.9);
    drawSection(resumeImage, "Email: " + email, 50, 190, 0.9);
    drawSection(resumeImage, "Phone: " + phone, 50, 230, 0.9);

    drawHeader(resumeImage, "Summary", 50, 300);
    drawSection(resumeImage, summary, 50, 340, 0.8);

    drawHeader(resumeImage, "Skills", 50, 400);
    drawSection(resumeImage, skills, 50, 440, 0.8);

    drawHeader(resumeImage, "Education", 50, 500);
    drawSection(resumeImage, "College: " + college, 50, 540, 0.8);
    drawSection(resumeImage, "Degree: " + degree, 50, 580, 0.8);

    drawHeader(resumeImage, "Work Experience", 50, 640);
    drawSection(resumeImage, workExperience, 50, 680, 0.8);

    drawHeader(resumeImage, "Achievements", 50, 740);
    drawSection(resumeImage, achievements, 50, 780, 0.8);

    drawHeader(resumeImage, "Projects", 50, 840);
    drawSection(resumeImage, projects, 50, 880, 0.8);

    cv::imwrite("interactive_resume_with_photo.png", resumeImage);
    std::cout << "Resume saved as 'interactive_resume_with_photo.png'" << std::endl;

    cv::imshow("Resume Builder", resumeImage);
    cv::waitKey(0);
    return 0;
}