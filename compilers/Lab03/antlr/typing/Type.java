package typing;

// Enumeração dos tipos primitivos que podem existir em EZLang.
public enum Type {
	INT_TYPE {
		public String toString() {
            return "int";
        }
	},
    REAL_TYPE {
		public String toString() {
			return "real";
		}
	},
    BOOL_TYPE {
		public String toString() {
            return "bool";
        }
	},
    STR_TYPE {
		public String toString() {
            return "string";
        }
	}
}
