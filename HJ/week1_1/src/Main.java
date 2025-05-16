import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        List<Person> personList = new ArrayList<>();

        for (int i=0; i<n; i++){
            int age = sc.nextInt();
            String name = sc.next();
            personList.add(new Person(age, name));
        }

        Collections.sort(personList, Comparator.comparingInt(p->p.age));

        for (Person p: personList){
            System.out.println(p.age + " " + p.name);
        }
    }

    static class Person{
        int age;
        String name;

        Person(int age, String name) {
            this.age = age;
            this.name = name;
        }
    }
}

