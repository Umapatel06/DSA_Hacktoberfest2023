/* 
Make sure you have the BCrypt library added to your project. 
  You can add it as a Maven or Gradle dependency, 
       or you can download the JAR file from https://github.com/patrickfav/bcrypt. */

import org.mindrot.jbcrypt.BCrypt;

public class PasswordHashingEx {
    public static void main(String[] args) {
        String password = "mySecretPassword";
        String hashedPassword = hashPassword(password);

        // Verify a password against the hashed version
        boolean passwordMatches = checkPassword("mySecretPassword", hashedPassword);
        System.out.println("Password matches: " + passwordMatches);
    }

    public static String hashPassword(String password) {
        // Generate a salt for the password
        String salt = BCrypt.gensalt(12); 

        // Hash the password with the salt
        String hashedPassword = BCrypt.hashpw(password, salt);

        return hashedPassword;
    }

    public static boolean checkPassword(String password, String hashedPassword) {
        // Check if the entered password matches the stored hashed password
        return BCrypt.checkpw(password, hashedPassword);
    }
}
