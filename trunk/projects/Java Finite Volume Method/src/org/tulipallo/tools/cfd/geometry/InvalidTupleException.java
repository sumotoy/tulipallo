/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package org.tulipallo.tools.cfd.geometry;

/**
 *
 * @author murrellrr
 */
public class InvalidTupleException extends RuntimeException {
    public InvalidTupleException(final Throwable cause) {
        super(cause);
    }

    public InvalidTupleException(final String message, final Throwable cause) {
        super(message, cause);
    }

    public InvalidTupleException(final String message) {
        super(message);
    }

    public InvalidTupleException() {
    }
}
