---
marp: true
theme: base
paginate: true
#header: 'Header content'
footer: 'Jan H. Krüger OIS1 - Basler Versicherungen | What are Feature Toggles'
---

# What are Feature Toggles?

Changes in the way to develop and bring to live new features on production.

---


   public static void main(String args[]) throws IOException {

      Properties propertyDictionary = readPropertiesFile("flags.properties");
   
      if (   propertyDictionary.getProperty("isPHV").equals("true") ) {
         System.out.println("Hello PHV");
      }
      else {
         System.out.println("Welcome back, KFZ");
      }
   }


---


   if ( getEnvVar("hello") != "" ) {
    std::cout << "Hello World" << std::endl;
  }
  else {
    std::cout << "Hello Mars" << std::endl;
  }

