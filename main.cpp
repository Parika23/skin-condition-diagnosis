#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Abstract base class for skin conditions.
class SkinIssue {
public:
    virtual string getName() const = 0;
    virtual string getVitaminDeficiency() const = 0;
    virtual vector<string> getRecommendedFruits() const = 0;
    virtual vector<string> getRecommendedVegetables() const = 0;

    virtual void displaySolution() const {
        cout << "\n========================================\n";
        cout << "Possible Skin Condition: " << getName() << '\n';
        cout << "Possible Nutritional Deficiency: "
             << getVitaminDeficiency() << '\n';

        cout << "Recommended Fruits: ";
        for (const auto& fruit : getRecommendedFruits()) {
            cout << fruit << "  ";
        }
        cout << '\n';

        cout << "Recommended Vegetables: ";
        for (const auto& vegetable : getRecommendedVegetables()) {
            cout << vegetable << "  ";
        }
        cout << '\n';
        cout << "========================================\n";
    }

    virtual ~SkinIssue() = default;
};

// Derived class for Acne.
class Acne : public SkinIssue {
public:
    string getName() const override {
        return "Acne";
    }

    string getVitaminDeficiency() const override {
        return "Vitamin A, Zinc";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Oranges", "Berries", "Avocado"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Spinach", "Sweet Potato", "Carrots"};
    }
};

// Derived class for Dermatitis.
class Dermatitis : public SkinIssue {
public:
    string getName() const override {
        return "Dermatitis";
    }

    string getVitaminDeficiency() const override {
        return "Vitamin D, Omega-3";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Apples", "Blueberries", "Papaya"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Broccoli", "Kale", "Pumpkin"};
    }
};

// Derived class for Rosacea.
class Rosacea : public SkinIssue {
public:
    string getName() const override {
        return "Rosacea";
    }

    string getVitaminDeficiency() const override {
        return "Vitamin B2, B3";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Watermelon", "Bananas", "Citrus fruits"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Spinach", "Mushrooms", "Cucumber"};
    }
};

// Derived class for Vitiligo.
class Vitiligo : public SkinIssue {
public:
    string getName() const override {
        return "Vitiligo";
    }

    string getVitaminDeficiency() const override {
        return "Folic Acid, Vitamin C";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Pineapple", "Citrus", "Pomegranate"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Cauliflower", "Bell Peppers", "Broccoli"};
    }
};

// Derived class for Psoriasis.
class Psoriasis : public SkinIssue {
public:
    string getName() const override {
        return "Psoriasis";
    }

    string getVitaminDeficiency() const override {
        return "Vitamin D, Selenium";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Papaya", "Mango", "Avocado"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Tomatoes", "Spinach", "Brussels Sprouts"};
    }
};

// Derived class for Eczema.
class Eczema : public SkinIssue {
public:
    string getName() const override {
        return "Eczema";
    }

    string getVitaminDeficiency() const override {
        return "Omega-3, Vitamin E";
    }

    vector<string> getRecommendedFruits() const override {
        return {"Avocado", "Blueberries", "Pears"};
    }

    vector<string> getRecommendedVegetables() const override {
        return {"Spinach", "Broccoli", "Sweet Potato"};
    }
};

// Handles the questionnaire and rule-based diagnosis.
class SkinDiagnosis {
private:
    vector<int> answers;
    vector<string> questions;

    int readYesNo() const {
        int answer;

        while (true) {
            cin >> answer;

            if (cin.good() && (answer == 0 || answer == 1)) {
                return answer;
            }

            cout << "Please enter 1 for Yes or 0 for No: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    SkinDiagnosis() {
        questions = {
            "Do you experience frequent breakouts?",
            "Do you have patches of dry, flaky skin?",
            "Do you blush easily or have persistent redness?",
            "Do you notice pale patches on your skin?",
            "Do you have thick, scaly skin patches?",
            "Do you experience itching and irritation?",
            "Do your symptoms worsen in the sun?",
            "Is your skin prone to inflammation?",
            "Do you notice a burning sensation on your skin?",
            "Does your skin react poorly to stress?",
            "Do you experience discoloration or blotchy patches?",
            "Does your skin feel overly dry despite moisturizing?"
        };

        answers.resize(questions.size(), 0);
    }

    void askQuestions() {
        cout << "\nAnswer the following questions using:\n";
        cout << "1 = Yes, 0 = No\n\n";

        for (size_t i = 0; i < questions.size(); ++i) {
            cout << (i + 1) << ". " << questions[i] << '\n';
            cout << "Answer: ";
            answers[i] = readYesNo();
            cout << '\n';
        }
    }

    unique_ptr<SkinIssue> diagnose() const {
        // Pattern-matching rules from the original project.
        if (answers[0]) {
            return make_unique<Acne>();
        }

        if (answers[1] && (answers[5] || answers[11])) {
            return make_unique<Dermatitis>();
        }

        if (answers[2] && (answers[6] || answers[8])) {
            return make_unique<Rosacea>();
        }

        if (answers[3] && answers[10]) {
            return make_unique<Vitiligo>();
        }

        if (answers[1] && answers[4] && answers[6]) {
            return make_unique<Psoriasis>();
        }

        if (answers[5] && answers[7] && answers[11]) {
            return make_unique<Eczema>();
        }

        return nullptr;
    }
};

// Integrates the diagnosis workflow.
class SkinSolutionPlatform {
private:
    SkinDiagnosis diagnosis;

public:
    void startDiagnosis() {
        diagnosis.askQuestions();

        auto issue = diagnosis.diagnose();

        if (issue) {
            issue->displaySolution();
        } else {
            cout << "\nNo clear diagnosis was found based on the selected "
                    "symptoms.\n";
            cout << "Please consult a qualified dermatologist for "
                    "professional evaluation.\n";
        }
    }
};

int main() {
    cout << "========================================\n";
    cout << "   SKIN CONDITION SCREENING SYSTEM\n";
    cout << "========================================\n";

    SkinSolutionPlatform platform;
    platform.startDiagnosis();

    cout << "\nThis program is an educational rule-based prototype and is not a "
            "medical diagnostic tool.\n";

    return 0;
}
